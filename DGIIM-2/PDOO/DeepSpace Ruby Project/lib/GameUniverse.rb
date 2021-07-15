#encoding:utf-8

require_relative 'GameUniverseToUI'
require_relative 'SpaceStation'
require_relative 'GameStateController'
require_relative 'EnemyStarShip'
require_relative 'Dice'
require_relative 'ShotResult'
require_relative 'CombatResult'
require_relative 'GameCharacter'
require_relative 'CardDealer'
require_relative 'PowerEfficientSpaceStation'
require_relative 'BetaPowerEfficientSpaceStation'
require_relative 'SpaceCity'
require_relative 'Transformation'

module Deepspace
  class GameUniverse
    @@WIN = 10

    attr_reader :gameState

    def initialize
      @currentStationIndex = -1
      @turns = 0
      @gameState = GameStateController.new
      @currentEnemy = nil
      @dice = Dice.new
      @currentStation = nil
      @spaceStations = Array.new
      @haveSpaceCity = false
    end

    def combatGo(station, enemy)
      ch = @dice.firstShot
      if ch == GameCharacter::ENEMYSTARSHIP
        fire = enemy.fire
        result = station.receiveShot(fire)
        if result == ShotResult::RESIST
          fire = station.fire
          result = enemy.receiveShot(fire)
          enemyWins = (result == ShotResult::RESIST)
        else
          enemyWins = true
        end
      else
        fire = station.fire
        result = enemy.receiveShot(fire)
        enemyWins = (result == ShotResult::RESIST)
      end

      if enemyWins
        s = station.getSpeed
        moves = @dice.spaceStationMoves(s)
        if !moves
          damage = enemy.damage
          station.setPendingDamage(damage)
          combatResult = CombatResult::ENEMYWINS
        else
          station.move
          combatResult = CombatResult::STATIONESCAPES
        end
      else
        aLoot = enemy.loot
        r = station.setLoot(aLoot)

        if r == Transformation::GETEFFICIENT
          makeStationEfficient
          combatResult = CombatResult::STATIONWINSANDCONVERTS
        elsif r == Transformation::SPACECITY
          createSpaceCity
          combatResult = CombatResult::STATIONWINSANDCONVERTS
        else
          combatResult = CombatResult::STATIONWINS
        end
      end

      @gameState.next(@turns, @spaceStations.size)
      return combatResult
    end

    public

    def combat
      state = @gameState.state
      if state == GameState::BEFORECOMBAT || state == GameState::INIT
        return combatGo(@currentStation, @currentEnemy)
      else
        return CombatResult::NOCOMBAT
      end
    end

    def discardHangar
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.discardHangar
      end
    end

    def discardShieldBooster(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.discardShieldBooster(i)
      end
    end

    def discardShieldBoosterInHangar(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.discardShieldBoosterInHangar(i)
      end
    end

    def discardWeapon(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.discardWeapon(i)
      end
    end

    def discardWeaponInHangar(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.discardWeaponInHangar(i)
      end
    end

    def state
      @gameState.state
    end

    def getUIversion
      GameUniverseToUI.new(@currentStation, @currentEnemy)
    end

    def haveAWinner
      @currentStation.nMedals >= @@WIN
    end

    def init(names)
      state = @gameState.state
      size = names.size
      if state == Deepspace::GameState::CANNOTPLAY
        dealer = CardDealer.instance

        for i in (0..size - 1)
          supplies = dealer.nextSuppliesPackage
          station = SpaceStation.new(names[i], supplies)
          nh = @dice.initWithNHangars
          nw = @dice.initWithNWeapons
          ns = @dice.initWithNShields

          lo = Loot.new(0, nw, ns, nh, 0)
          station.setLoot(lo)
          @spaceStations.push(station)
        end

        @currentStationIndex = @dice.whoStarts(size)
        @currentStation = @spaceStations[@currentStationIndex]
        @currentEnemy = dealer.nextEnemy
        @gameState.next(@turns, size)
      end
    end

    def mountShieldBooster(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.mountShieldBooster(i)
      end
    end

    def mountWeapon(i)
      if state == GameState::INIT || state == GameState::AFTERCOMBAT
        @currentStation.mountWeapon(i)
      end
    end

    def nextTurn
      state = @gameState.state
      if state == Deepspace::GameState::AFTERCOMBAT
        stationState = @currentStation.validState
        if (stationState)
          @currentStationIndex = (@currentStationIndex + 1) % @spaceStations.length
          @currentStation = @spaceStations[@currentStationIndex]
          @turns += 1
          @currentStation.cleanUpMountedItems
          dealer = CardDealer.instance
          @currentEnemy = dealer.nextEnemy
          @gameState.next(@turns, @spaceStations.length)
          return true
        end
      end
      return false
    end

    def makeStationEfficient
      if @dice.extraEfficiency
        @currentStation = PowerEfficientSpaceStation.new(@currentStation)
      else
        @currentStation = BetaPowerEfficientSpaceStation.new(@currentStation)
      end
      @spaceStations[@currentStationIndex] = @currentStation
    end

    def createSpaceCity
      rest = []
      if !@haveSpaceCity
        for i in 0..@spaceStations.length-1
          if @currentStationIndex != i
            rest.push(@spaceStations[i])
          end
        end
        @currentStation = SpaceCity.new(@currentStation, rest)
        @spaceStations[@currentStationIndex] = @currentStation
        @haveSpaceCity = true
      end
    end

    def to_s
      getUIversion
    end

  end
end
#encoding:utf-8

require_relative 'SpaceStationToUI'
require_relative 'SuppliesPackage'
require_relative 'Hangar'
require_relative 'Weapon'
require_relative 'WeaponType'
require_relative 'ShieldBooster'
require_relative 'Damage'
require_relative 'Loot'
require_relative 'CardDealer'
require_relative 'Transformation'

module Deepspace
  class SpaceStation
    @@MAXFUEL = 100.0
    @@SHIELDLOSSPERUNITSHOT = 0.1

    attr_reader :ammoPower
    attr_reader :fuelUnits
    attr_reader :hangar
    attr_reader :name
    attr_reader :nMedals
    attr_reader :pendingDamage
    attr_reader :weapons
    attr_reader :shieldBoosters
    attr_reader :shieldPower

    def initialize(n,s)
      @ammoPower = s.ammoPower
      @name = n
      @nMedals = 0
      @shieldPower = s.shieldPower
      @pendingDamage = nil
      @weapons = Array.new
      @shieldBoosters = Array.new
      @hangar = nil

      assignFuelValue(s.fuelUnits)
    end

    def copy(station)
      @ammoPower = station.ammoPower
      @name = station.name
      @nMedals = station.nMedals
      @shieldPower = station.shieldPower
      @pendingDamage = station.pendingDamage
      @weapons = station.weapons.dup
      @shieldBoosters = station.shieldBoosters.dup
      @hangar = station.hangar

      assignFuelValue(station.fuelUnits)
    end

    private

    def assignFuelValue(f)
      if f > @@MAXFUEL
        @fuelUnits = @@MAXFUEL
      else
        @fuelUnits = f
      end
    end

    def cleanPendingDamage
      if @pendingDamage.hasNoEffect
        @pendingDamage = nil
      end
    end

    public

    def cleanUpMountedItems
      weaponsWithNoUses = []
      @weapons.each { |w|
        if w.uses == 0
          weaponsWithNoUses.push(w)
        end
      }
      weaponsWithNoUses.each { |wNoUses|
        @weapons.delete(wNoUses)
      }

      sbWithNoUses = []
      @shieldBoosters.each { |sb|
        if sb.uses == 0
          sbWithNoUses.push(sb)
        end
      }
      sbWithNoUses.each { |sbNoUses|
        @shieldBoosters.delete(sbNoUses)
      }
    end

    def discardHangar
      @hangar = nil
    end

    def fire
      size = @weapons.size
      factor = 1

      for i in 0..size - 1
        w = @weapons[i]
        factor *= w.useIt
      end
      @ammoPower * factor
    end

    def setPendingDamage(d)
      @pendingDamage = d.adjust(@weapons, @shieldBoosters)
      cleanPendingDamage
    end

    def mountWeapon(i)
      if @hangar != nil && (0 <= i)
        weapon = @hangar.weapons[i]
        @hangar.removeWeapon(i)
        if weapon != nil
          @weapons.push(weapon)
        end
      end
    end

    def mountShieldBooster(i)
      if @hangar != nil && (0 <= i)
        shieldBooster = @hangar.shieldBoosters[i]
        @hangar.removeShieldBooster(i)
        if shieldBooster != nil
          @shieldBoosters.push(shieldBooster)
        end
      end
    end

    def discardShieldBooster(i)
      if (0 <= i) && (i < @shieldBoosters.length)
        @shieldBoosters.delete_at(i)

        if @pendingDamage != nil
          @pendingDamage.discardShieldBooster
          cleanPendingDamage
        end
      end
    end

    def discardShieldBoosterInHangar(i)
      if @hangar != nil
        @hangar.removeShieldBooster(i)
      end
    end

    def discardWeapon(i)
      if (0 <= i) && (i < @weapons.length)
        weapon = @weapons.delete_at(i)

        if @pendingDamage != nil
          @pendingDamage.discardWeapon(weapon)
          cleanPendingDamage
        end
      end
    end

    def discardWeaponInHangar(i)
      if @hangar != nil
        @hangar.removeWeapon(i)
      end
    end

    def getSpeed
      @fuelUnits / @@MAXFUEL
    end

    def getUIversion
      SpaceStationToUI.new(self)
    end

    def move
      @fuelUnits -= getSpeed
      if fuelUnits < 0
        @fuelUnits = 0
      end
    end

    def protection
      size = @shieldBoosters.size
      factor = 1
      for i in (0..size - 1)
        s = @shieldBoosters[i]
        factor += s.useIt
      end
      @shieldPower * factor
    end

    def receiveHangar(h)
      if @hangar == nil
        @hangar = h
      end
    end

    def receiveShieldBooster(s)
      if @hangar != nil
        return @hangar.addShieldBooster(s)
      end
      return false
    end

    def receiveShot(shot)
      myProtection = protection
      if myProtection >= shot
        @shieldPower -= @@SHIELDLOSSPERUNITSHOT * shot
        @shieldPower = [0.0, @shieldPower].max
        return ShotResult::RESIST
      end
      @shieldPower = 0.0
      return ShotResult::DONOTRESIST
    end

    def receiveSupplies(s)
      @ammoPower += s.ammoPower
      @fuelUnits += s.fuelUnits
      @shieldPower += s.shieldPower

      if fuelUnits > @@MAXFUEL
        @fuelUnits = @@MAXFUEL
      end
    end

    def receiveWeapon(w)
      if @hangar != nil
        return @hangar.addWeapon(w)
      end
      return false
    end

    def setLoot(loot)
      dealer = CardDealer.instance
      h = loot.nHangars
      if h > 0
        hangar = dealer.nextHangar
        receiveHangar(hangar)
      end

      elements = loot.nSupplies
      for i in (1..elements)
        sup = dealer.nextSuppliesPackage
        receiveSupplies(sup)
      end

      elements = loot.nWeapons
      for i in (1..elements)
        weap = dealer.nextWeapon
        receiveWeapon(weap)
      end

      elements = loot.nShields
      for i in (1..elements)
        sh = dealer.nextShieldBooster
        receiveShieldBooster(sh)
      end

      medals = loot.nMedals
      @nMedals += medals

      if loot.efficient
        return Transformation::GETEFFICIENT
      elsif loot.spaceCity
        return Transformation::SPACECITY
      else
        return Transformation::NOTRANSFORM
      end
    end

    def to_s
      getUIversion
    end

    def validState
      @pendingDamage == nil || @pendingDamage.hasNoEffect
    end
  end
end
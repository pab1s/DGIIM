#encoding: utf-8
module Deepspace
  require_relative 'GameCharacter'

  class Dice
    def initialize
      @NHANGARSPROB = 0.25
      @NSHIELDSPROB = 0.25
      @NWEAPONSPROB = 0.33
      @FIRSTSHOTPROB = 0.50
      @EXTRAEFFICIENCYPROB = 0.80
      @generator = Random.new()
    end

    def initWithNHangars
      value = 0
      if @generator.rand(1.0) < @NHANGARSPROB
        value = 1
      end
      value
    end

    def initWithNWeapons
      prob = @generator.rand(1.0)
      value = 3
      if prob <= @NWEAPONSPROB
        value = 1
      elsif prob > @NWEAPONSPROB && prob < 2 * @NWEAPONSPROB
        value = 2
      end
      value
    end

    def initWithNShields
      value = 0
      if @generator.rand(1.0) < @NSHIELDSPROB
        value = 1
      end
      value
    end

    def whoStarts(nPlayers)
      rand(nPlayers)
    end

    def firstShot
      value = GameCharacter::ENEMYSTARSHIP

      if @generator.rand(1.0) <= @FIRSTSHOTPROB
        value = GameCharacter::SPACESTATION
      end
      value
    end

    def spaceStationMoves(speed)
      prob = rand()
      prob < speed
    end

    def extraEfficiency
      @generator.rand(1.0) < @EXTRAEFFICIENCYPROB
    end

    def to_s
      "INIT WITH NHANGARS: " + initWithNHangars.to_s + " - INIT WITH NWEAPONS: " + initWithNWeapons.to_s + " - INIT WITH NSHIELDS: " + initWithNShields.to_s + " - FIRST SHOT: " + firstShot.to_s
    end
  end
end
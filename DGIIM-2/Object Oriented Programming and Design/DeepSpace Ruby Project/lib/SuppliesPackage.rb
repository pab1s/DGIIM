#encoding: utf-8
module Deepspace
  class SuppliesPackage
    def initialize(a, f, s)
      @ammoPower = a
      @fuelUnits = f
      @shieldPower = s
    end

    def self.newCopy(s)
      new(s.ammoPower, s.fuelUnits, s.shieldPower)
    end

    public

    def ammoPower
      @ammoPower
    end

    def fuelUnits
      @fuelUnits
    end

    def shieldPower
      @shieldPower
    end

    def to_s
      "AMMO POWER: " + @ammoPower.to_s + " - FUEL UNITS: " + @fuelUnits.to_s + " - SHIELD POWER: " + @shieldPower.to_s
    end
  end
end
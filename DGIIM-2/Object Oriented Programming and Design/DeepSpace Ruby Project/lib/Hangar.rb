#encoding: utf-8

require_relative 'Weapon'
require_relative 'ShieldBooster'
require_relative 'HangarToUI'

module Deepspace
  class Hangar
    attr_reader :maxElements
    attr_reader :shieldBoosters
    attr_reader :weapons

    def initialize(c)
      @maxElements = c
      @weapons = Array.new
      @shieldBoosters = Array.new
    end

    def self.newCopy(h)
      hangarCopy = new(h.maxElements)
      h.shieldBoosters.each { |sB|
        hangarCopy.addShieldBooster(sB)
      }
      h.weapons.each { |w|
        hangarCopy.addWeapon(w)
      }
      hangarCopy
    end

    public

    def getUIversion
      HangarToUI.new(self)
    end

    private

    def spaceAvailable
      (@weapons.size + @shieldBoosters.size) < @maxElements
    end

    public

    def addWeapon(w)
      if spaceAvailable
        @weapons.push(w)
        value = true
      else
        value = false
      end
      value
    end

    def addShieldBooster(s)
      if spaceAvailable
        @shieldBoosters.push(s)
        return true
      else
        return false
      end
    end

    def removeWeapon(w)
      if w < 0 || @weapons.size <= w
        return nil
      else
        return @weapons.delete_at(w)
      end
    end

    def removeShieldBooster(s)
      if s < 0 || @shieldBoosters.size <= s
        return nil
      else
        return @shieldBoosters.delete_at(s)
      end
    end

    def to_s
      getUIversion
    end
  end
end
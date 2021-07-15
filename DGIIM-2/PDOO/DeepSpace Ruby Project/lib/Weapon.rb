#encoding: utf-8

require_relative 'WeaponToUI'

module Deepspace
  class Weapon
    def initialize(n, t, u)
      @name = n
      @type = t
      @uses = u
    end

    def self.newCopy(s)
      new(s.name, s.type, s.uses)
    end

    public

    def name
      @name
    end

    def type
      @type
    end

    def uses
      @uses
    end

    def power
      @type.power
    end

    def useIt
      if @uses > 0
        @uses -= 1
        value = power
      else
        value = 1.0
      end
      return value
    end

    def getUIversion
      WeaponToUI.new(self)
    end

    def to_s
      self.getUIversion
    end
  end
end
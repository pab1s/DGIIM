#encoding:utf-8

require_relative 'WeaponType'
require_relative 'Weapon'
require_relative 'DamageToUI'

module Deepspace
  class Damage
    private_class_method :new

    @@NOTNWEAPONS = -1

    attr_reader :nShields

    def initialize(ns)
      @nShields = ns
    end

    public

    def adjust(w,s)
      #Abstract
    end

    def discardShieldBooster
      if @nShields > 0
        @nShields -= 1
      end
      nil
    end

    def hasNoEffect
      return @nShields == 0
    end
  end
end

require_relative 'NumericDamageToUI'
require_relative 'Damage'

module Deepspace
  class NumericDamage < Damage
    public_class_method :new

    attr_reader :nWeapons

    def initialize(nw, ns)
      super(ns)
      @nWeapons = nw
    end

    def copy
      NumericDamage.new(@nWeapons, @nShields)
    end

    public

    def discardWeapon(w)
      if @nWeapons > 0
        @nWeapons -= 1
      end
    end

    def hasNoEffect
      @nWeapons == 0 && super
    end

    def adjust(w, s)
      retNShields = [@nShields,s.length].min
      retNWeapons = [@nWeapons,w.length].min
      NumericDamage.new(retNWeapons, retNShields)
    end

    def getUIversion
      NumericDamageToUI.new(self)
    end

    def to_s
      getUIversion
    end
  end
end
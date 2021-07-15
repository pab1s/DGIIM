require_relative 'SpecificDamageToUI'
require_relative'WeaponType'
require_relative 'Damage'

module Deepspace
  class SpecificDamage < Damage
    public_class_method :new

    attr_reader :weapons

    def initialize(w, ns)
      super(ns)
      @weapons = w.dup
    end

    def copy
        SpecificDamage.new(@weapons, @nShields)
    end

    private

    def arrayContainsType(w, s)
      for i in 0...w.length
        if w[i].type == s
          return i
        end
      end
      return @@NOTNWEAPONS
    end

    public

    def discardWeapon(w)
      if @weapons != nil
        index = @weapons.index(w.type)
        if index != nil
          @weapons.delete_at(index)
        end
      end
    end

    def hasNoEffect
      @weapons.empty? && super
    end

    def adjust(w, s)
      arrayWeaponType = @weapons.clone
      arrayWeaponCopy = w.clone
      retNShields = [@nShields,s.length].min
      retWeapons = []

      @weapons.each { |weaponType|
        index = arrayContainsType(arrayWeaponCopy, weaponType)
        if index != @@NOTNWEAPONS
          arrayWeaponCopy.delete_at(index)
          retWeapons.push(weaponType)
        end
        arrayWeaponType.delete(weaponType)
      }
      SpecificDamage.new(retWeapons, retNShields)
    end

    def getUIversion
      SpecificDamageToUI.new(self)
    end

    def to_s
      getUIversion
    end

  end
end
#encoding: utf-8
require_relative 'EnemyToUI'

module Deepspace
  class EnemyStarShip
    attr_reader :name
    attr_reader :ammoPower
    attr_reader :shieldPower
    attr_reader :loot
    attr_reader :damage

    def initialize(n, a, s, l, d)
      @name = n
      @ammoPower = a
      @shieldPower = s
      @loot = l
      @damage = d
    end

    def self.newCopy(e)
      EnemyStarShip.new(e.name, e.ammoPower, e.shieldPower, e.loot, e.damage)
    end

    def fire
      @ammoPower
    end

    def protection
      @shieldPower
    end

    def receiveShot(shot)
      retval = ShotResult::RESIST
      if shot > @shieldPower
        retval = ShotResult::DONOTRESIST
      end
      retval
    end

    def getUIversion
      EnemyToUI.new(self)
    end

    def to_s
      getUIversion
    end

  end
end
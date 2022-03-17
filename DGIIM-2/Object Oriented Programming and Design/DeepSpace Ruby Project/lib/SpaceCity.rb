require_relative 'SpaceStation'
require_relative 'Transformation'

module Deepspace
  class SpaceCity < SpaceStation

    attr_reader :collaborators

    def initialize(base, rest)
      @base = base
      @collaborators = rest
      copy(base)
    end

    def fire
      power = super
      @collaborators.each { |ss| power += ss.fire }
      power
    end

    def protection
      shield = super
      @collaborators.each { |ss| shield += ss.protection }
      shield
    end

    def setLoot(loot)
      super(loot)
      Transformation::NOTRANSFORM
    end

  end
end
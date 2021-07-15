require_relative 'SpaceStation'
require_relative 'Transformation'
require_relative 'PowerEfficientSpaceStationToUI'

module Deepspace
  class PowerEfficientSpaceStation < SpaceStation
    private
    @@EFFICIENCYFACTOR = 1.10

    public
    def initialize(ss)
      copy(ss)
    end

    def fire
      super * @@EFFICIENCYFACTOR
    end

    def protection
      super * @@EFFICIENCYFACTOR
    end

    def setLoot(loot)
      super
      Transformation::NOTRANSFORM
    end

    def getUIversion
      PowerEfficientSpaceStationToUI.new(self)
    end

    def to_s
      getUIversion
    end
  end
end
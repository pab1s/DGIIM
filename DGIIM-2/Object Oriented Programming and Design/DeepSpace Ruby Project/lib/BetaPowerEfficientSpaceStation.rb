require_relative 'PowerEfficientSpaceStation'
require_relative 'Dice'
require_relative 'BetaPowerEfficientSpaceStationToUI'

module Deepspace
  class BetaPowerEfficientSpaceStation < PowerEfficientSpaceStation
    private
    @@EXTRAEFFICIENCY = 1.2

    public
    def initialize(ss)
      @dice = Dice.new
      super
    end

    def fire
      if @dice.extraEfficiency
        super * @@EXTRAEFFICIENCY
      else
        super
      end
    end

    def getUIversion
      BetaPowerEfficientSpaceStationToUI.new(self)
    end

    def to_s
      getUIversion
    end

  end
end
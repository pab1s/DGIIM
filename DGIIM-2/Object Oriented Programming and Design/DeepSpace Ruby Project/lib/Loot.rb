#encoding: utf-8
require_relative 'LootToUI'
module Deepspace
  class Loot

    attr_reader :nSupplies, :nWeapons, :nShields, :nHangars, :nMedals, :efficient, :spaceCity

    def initialize(supplies, weapons, shields, hangars, medals, ef=false, city=false)
      @nSupplies = supplies
      @nWeapons = weapons
      @nShields = shields
      @nHangars = hangars
      @nMedals = medals
      @efficient = ef
      @spaceCity = city
    end

    public

    def getUIversion
      LootToUI.new(self)
    end

    def to_s
      self.getUIversion
    end
  end
end
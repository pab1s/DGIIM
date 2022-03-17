#encoding: utf-8

require_relative 'ShieldToUI'

module Deepspace
  class ShieldBooster
    def initialize(n, b, u)
      @name = n
      @boost = b
      @uses = u
    end

    def self.newCopy(s)
      new(s.name, s.boost, s.uses)
    end

    public

    def name
      @name
    end

    def boost
      @boost
    end

    def uses
      @uses
    end

    def useIt
      if @uses > 0
        @uses -= 1
        value = @boost
      else
        value = 1.0
      end
      value
    end

    def getUIversion
      ShieldToUI.new(self)
    end

    def to_s
      self.getUIversion
    end
  end
end
#encoding: utf-8
require_relative "CombatResult"
require_relative "GameCharacter"
require_relative "ShotResult"
require_relative "WeaponType"
require_relative "Loot"
require_relative "SuppliesPackage"
require_relative "ShieldBooster"
require_relative "Weapon"
require_relative "Dice"

module Deepspace
  class TestP1
    l = Loot.new(1, 2, 3, 4, 5);
    sp1 = SuppliesPackage.new(25.0, 40.0, 5.0)
    sp2 = SuppliesPackage.newCopy(sp1)
    sb1 = ShieldBooster.new("Strong", 4.5, 3)
    sb2 = ShieldBooster.newCopy(sb1)
    w1 = Weapon.new("Laser Gun", WeaponType::LASER, 4)
    w2 = Weapon.newCopy(w1)
    dado = Dice.new

    #CombatResult
    puts CombatResult::ENEMYWINS
    puts CombatResult::NOCOMBAT
    puts CombatResult::STATIONESCAPES
    puts CombatResult::STATIONWINS

    #GameCharacter
    puts GameCharacter::ENEMYSTARSHIP
    puts GameCharacter::SPACESTATION

    #ShotResult
    puts ShotResult::DONOTRESIST
    puts ShotResult::RESIST

    #WeaponType
    puts WeaponType::LASER.power
    puts WeaponType::MISSILE.power
    puts WeaponType::PLASMA.power

    #Loot
    puts l.nSupplies
    puts l.nWeapons
    puts l.nShields
    puts l.nHangars
    puts l.nMedals

    # SuppliesPackage
    puts sp1.ammoPower
    puts sp1.fuelUnits
    puts sp1.shieldPower

    puts sp2.ammoPower
    puts sp2.fuelUnits
    puts sp2.shieldPower

    #ShieldBooster
    puts "ShieldBooster 1: Trial"
    puts sb1.boost
    puts "Total inicial de usos: 3"
    for i in 1..6
      puts sb1.useIt
    end

    puts "ShieldBooster 2: Trial"
    puts sb2.boost
    puts "Total inicial de usos: 3"
    for i in 1..6
      puts sb2.useIt
    end

    #Weapon
    puts w1.uses
    puts w1.power
    puts "Total inicial de usos: 4"
    for i in 1..6
      w1.useIt
    end

    puts w2.uses
    puts w2.power
    puts "Total inicial de usos: 4"
    for i in 1..6
      w2.useIt
    end

    #Dice
    nh = 0
    ns = 0
    nw = 0
    sp = 0
    for i in 0..100
      puts dado.whoStarts(7)
      nh += dado.initWithNHangars
      ns += dado.initWithNShields
      nw += dado.initWithNWeapons
      if dado.firstShot == GameCharacter::SPACESTATION
        sp += 1
      end
    end
    puts nh / 100.0
    puts ns / 100.0
    puts nw / 100.0
    puts sp / 100.0
  end
end
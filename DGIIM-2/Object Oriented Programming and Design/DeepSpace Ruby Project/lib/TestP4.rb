#Inclusion de recursos
require_relative 'BetaPowerEfficientSpaceStation'
require_relative 'CombatResult'
require_relative 'Damage'
require_relative 'Dice'
require_relative 'EnemyStarShip'
require_relative 'GameCharacter'
require_relative 'GameState'
require_relative 'GameStateController'
require_relative 'GameUniverse'
require_relative 'Hangar'
require_relative 'Loot'
require_relative 'NumericDamage'
require_relative 'PowerEfficientSpaceStation'
require_relative 'ShieldBooster'
require_relative 'ShotResult'
require_relative 'SpaceCity'
require_relative 'SpaceStation'
require_relative 'SpecificDamage'
require_relative 'SuppliesPackage'
require_relative 'Transformation'
require_relative 'Weapon'
require_relative 'WeaponType'

#MODEL
module Deepspace
  #CLASS TEST
  class TestP4
    @@SEPARATOR = "\n/////////////////////////////////////////////////////////////////\n\n"
    
    private
    
    #Brief: Crea objetos loot para hacer el test
    def createLoot
      loot1 = Loot.new(1,2,3,4,5)
      loot2 = Loot.new(4,5,6,7,8)
      loot3 = Loot.new(7,8,9,10,11)
      
      loots = [loot1,loot2,loot3]
      return loots
    end
    
    #Brief: Crea objetos SuppliesPackage para hacer el test
    def createSuppliesPackage
      supplies1 = SuppliesPackage.new(2,3,5)
      supplies2 = SuppliesPackage.new(4,5,6)
      supplies3 = SuppliesPackage.new(7,8,9)
      
      supplies = [supplies1,supplies2,supplies3]
      return supplies
    end
    
    #Brief: Crea objetos Weapon para hacer el test
    def createWeapon
      weapon1 = Weapon.new("W1",WeaponType::LASER,5)
      weapon2 = Weapon.new("W2",WeaponType::MISSILE,7)
      weapon3 = Weapon.new("W3",WeaponType::PLASMA,10)
      
      weapons = [weapon1,weapon2,weapon3]
      return weapons
    end
    
    #Brief: Crea objetos ShieldBooster para hacer el test
    def createShieldBooster
      shield1 = ShieldBooster.new("S1",2.0,10)
      shield2 = ShieldBooster.new("S2",3.0,20)
      shield3 = ShieldBooster.new("S3",4.0,25)
      
      shields = [shield1,shield2,shield3]
      return shields
    end
    
    #Brief: Crea objetos Hangar para hacer el test
    def createHangar
      hangar1 = Hangar.new(3)
      hangar2 = Hangar.new(5)
      hangar3 = Hangar.new(8)
      
      hangars = [hangar1,hangar2,hangar3]
      return hangars
    end
    
    #Brief: Crea objetos DamageNumeric para hacer el test
    def createDamageNumeric
      damageNumeric1 = NumericDamage.new(0,0)
      damageNumeric2 = NumericDamage.new(2,4)
      damageNumeric3 = NumericDamage.new(5,7)
      
      damages = [damageNumeric1,damageNumeric2,damageNumeric3]
      return damages
    end
    
    #Brief: Crea objetos DamageSpecific para hacer el test
    def createDamageSpecific
      array1 = [WeaponType::LASER, WeaponType::MISSILE, WeaponType::PLASMA]
      array2 = [WeaponType::LASER, WeaponType::LASER, WeaponType::LASER,
        WeaponType::LASER, WeaponType::LASER]
      array3 = [WeaponType::LASER, WeaponType::MISSILE, WeaponType::MISSILE,
        WeaponType::MISSILE, WeaponType::PLASMA]
      array4 = [WeaponType::PLASMA]
      array5 = [WeaponType::LASER, WeaponType::MISSILE]
      array6 = [WeaponType::PLASMA, WeaponType::PLASMA]
      
      dSpecific1 = SpecificDamage.new(array1,1)
      dSpecific2 = SpecificDamage.new(array2,2)
      dSpecific3 = SpecificDamage.new(array3,3)
      dSpecific4 = SpecificDamage.new(array4,4)
      dSpecific5 = SpecificDamage.new(array5,5)
      dSpecific6 = SpecificDamage.new(array6,6)

      damages = [dSpecific1,dSpecific2,dSpecific3,dSpecific4,dSpecific5,dSpecific6]
      return damages
    end
    
    #Brief: Crea objetos EnemyStarShip para hacer el test
    def createEnemyStarShip
      loot = createLoot
      damage1 = createDamageNumeric
      damage2 = createDamageSpecific
      
      enemy1 = EnemyStarShip.new("E1",5,6,loot[0],damage1[0])
      enemy2 = EnemyStarShip.new("E2",10,20,loot[1],damage2[1])
      enemy3 = EnemyStarShip.new("E3",50,100,loot[2],damage2[4])
        
      enemies = [enemy1,enemy2,enemy3]
      return enemies
    end
    
    #Brief: Crea objeto SpaceStation para hacer el test
    def createSpaceStation
      supplies = createSuppliesPackage
      
      s1 = SpaceStation.new("Tatooine",supplies[0])
      s2 = SpaceStation.new("A",supplies[0])
      s3 = SpaceStation.new("B",supplies[1])
      s4 = SpaceStation.new("C",supplies[1])
      s5 = SpaceStation.new("D",supplies[2])
      s6 = SpaceStation.new("E",supplies[2])
      
      stations = [s1,s2,s3,s4,s5,s6]
      return stations
    end
    
    #Brief: Crea objeto SpaceCity para hacer el test
    def createSpaceCity
      stations = createSpaceStation
      base = stations[0]
      stations.delete_at(0)
      
      return SpaceCity.new(base,stations)
    end
    
    #Brief: Crea objeto PowerEfficientSpaceStation para hacer el test
    def createPowerEfficient
      stations = createSpaceStation
      
      return PowerEfficientSpaceStation.new(stations[0])
    end
    
    #Brief: Crea objeto BetaPowerEfficientSpaceStation para hacer el test
    def createBetaPowerEfficient
      stations = createSpaceStation
      
      return BetaPowerEfficientSpaceStation.new(stations[0])
    end
    
    #==========================================================================
    
    #Brief: Titulo de test
    def titleTest(index,object,section)
      endline = "\n"
      sep = "=================================================================\n"
      test = "TEST [#{index}] #{object} : #{section}\n"
      
      puts endline + sep + test + sep
    end
    
    #==========================================================================
    
    #Brief: Constructor por defecto del test
    def initialize
      @loot = createLoot
      @suppliesPackage = createSuppliesPackage
      @weapon = createWeapon
      @shieldBooster = createShieldBooster
      @dice = Dice.new
      @hangar = createHangar
      @damageNumeric = createDamageNumeric
      @damageSpecific = createDamageSpecific
      @enemyStarShip = createEnemyStarShip
      @spaceStation = createSpaceStation
      @spaceCity = createSpaceCity
      @betaPowerEfficient = createBetaPowerEfficient
      @powerEfficient = createPowerEfficient
      @gameUniverse = GameUniverse.new
    end
    
    #==========================================================================
    
    public
    
    #Brief: Metodo de TEST
    #Param: array->Array de opciones
    def init(array)
      if array.include?(1)
        testPowerEfficient
        puts @@SEPARATOR
      end
      
      if array.include?(2)
        testBetaPowerEfficient
        puts @@SEPARATOR
      end
      
      if array.include?(3)
        testSpaceCity
        puts @@SEPARATOR
      end
      
      if array.include?(4)
        testNumericDamage
        puts @@SEPARATOR
      end
      
      if array.include?(5)
        testSpecificDamage
        puts @@SEPARATOR
      end
    end
    
    #==========================================================================
    
    private
    
    #Brief: Test 1 -> TEST POWEREFFICIENTSPACESTATION
    def testPowerEfficient
      #=============================================================
      #TESTS POWEREFFICIENTSPACESTATION
      # 1. TO_S
      # 2. FIRE Y PROTECTION METHOD
      #=============================================================
      
      index = 1
      object = "POWEREFFICIENTSPACESTATION"
      section = "METODO TO_S"
      
      titleTest(index,object,section)
      puts "#{@powerEfficient.to_s}"
      
      #=============================================================
      
      index += 1
      section = "METODOS FIRE Y PROTECTION"
      
      titleTest(index,object,section)
      puts "--> FIRE POWER: #{@powerEfficient.fire}"
      puts "--> PROTECTION POWER: #{@powerEfficient.protection}"
      
    end
    
    #Brief: Test 2 -> TEST BETAPOWEREFFICIENTSPACESTATION
    def testBetaPowerEfficient
      #=============================================================
      #TESTS BETAPOWEREFFICIENTSPACESTATION
      # 1. TO_S
      # 2. FIRE Y PROTECTION METHOD
      #=============================================================
      
      index = 1
      object = "BETAPOWEREFFICIENTSPACESTATION"
      section = "METODO TO_S"
      
      titleTest(index,object,section)
      puts "#{@betaPowerEfficient.to_s}"
      
      #=============================================================
      
      index += 1
      section = "METODOS FIRE Y PROTECTION"
      
      titleTest(index,object,section)
      puts "--> FIRE POWER: #{@betaPowerEfficient.fire}"
      puts "--> PROTECTION POWER: #{@betaPowerEfficient.protection}"
      
    end
    
    #Brief: Test 3 -> TEST SPACECITY
    def testSpaceCity
      #=============================================================
      #TESTS SPACECITY
      # 1. TO_S
      # 2. FIRE Y PROTECTION METHOD
      #=============================================================
      
      index = 1
      object = "SPACECITY"
      section = "METODO TO_S"
      
      titleTest(index,object,section)
      puts "#{@spaceCity.to_s}"
      
      #=============================================================
      
      index += 1
      section = "METODOS FIRE Y PROTECTION"
      
      titleTest(index,object,section)
      puts "--> FIRE POWER: #{@spaceCity.fire}"
      puts "--> PROTECTION POWER: #{@spaceCity.protection}"
    end
    
    #Brief: Test 4 -> TEST NUMERICDAMAGE
    def testNumericDamage
      #=============================================================
      #TESTS SPACECITY
      # 1. TO_S
      # 2. METODO ADJUST
      #=============================================================
      
      index = 1
      object = "NUMERICDAMAGE"
      section = "METODO TO_S"
      
      titleTest(index,object,section)
      puts "#{@damageNumeric[2].to_s}"
      
      #=============================================================
      
      index += 1
      section = "METODO ADJUST"
      
      titleTest(index,object,section)
      
      collectionWeapons = [Weapon.newCopy(@weapon[0]),Weapon.newCopy(@weapon[1]),Weapon.newCopy(@weapon[2]), Weapon.newCopy(@weapon[2])]
      collectionShields = [ShieldBooster.newCopy(@shieldBooster[0]),ShieldBooster.newCopy(@shieldBooster[1]),ShieldBooster.newCopy(@shieldBooster[1]),
        ShieldBooster.newCopy(@shieldBooster[2])]
        
      puts "AJUSTANDO AL DAMAGE ANTERIOR..."
      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each{ |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each{ |shields|
        puts "#{shields.to_s}"
      }
      
      damageAdjust = @damageNumeric[2].adjust(collectionWeapons,collectionShields)
      
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"
      
    end
    
    #Brief: Test 5 -> TEST SPECIFICDAMAGE
    def testSpecificDamage
      #=============================================================
      #TESTS SPECIFICDAMAGE
      # 1. TO_S
      # 2. METODO ADJUST
      #=============================================================
      
      index = 1
      object = "SPECIFICDAMAGE"
      section = "METODO TO_S"
      
      titleTest(index,object,section)
      puts "#{@damageSpecific[2].to_s}"
      
      #=============================================================
      
      index += 1
      section = "METODO ADJUST"
      
      titleTest(index,object,section)
      collectionWeapons = [Weapon.newCopy(@weapon[0]),Weapon.newCopy(@weapon[1]),Weapon.newCopy(@weapon[2]), Weapon.newCopy(@weapon[2])]
      collectionShields = [ShieldBooster.newCopy(@shieldBooster[0]),ShieldBooster.newCopy(@shieldBooster[1]),ShieldBooster.newCopy(@shieldBooster[1]),
        ShieldBooster.newCopy(@shieldBooster[2])]
        
      puts "AJUSTANDO AL DAMAGE ANTERIOR..."
      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each{ |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each{ |shields|
        puts "#{shields.to_s}"
      }
      
      damageAdjust = @damageSpecific[2].adjust(collectionWeapons,collectionShields)
      
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"
      
    end

  end #CLASS
end #MODULE

#===========================================================
#INICIO DE TEST
#===========================================================

#Usa este array para indicar los test que quieres ejecutar
#TESTS Y SU CORRESPONDIENTE OPCION
# -> 1. Test PowerEfficientSpaceStation
# -> 2. Test BetaPowerEfficientSpaceStation
# -> 3. Test SpaceCity
# -> 4. Test NumericDamage
# -> 5. Test SpecificDamage

#NOTA: Puedes transformar este rango por defecto en las opciones que tu
# quieras de la manera siguiente: [1,2,3,4,5]
array = (1..5)

#LANZADOR DE TEST DE PRACTICA
test = Deepspace::TestP4.new
test.init(array)

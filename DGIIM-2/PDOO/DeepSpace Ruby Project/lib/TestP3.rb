# File: TestP3.rb
# Brief: Test del programa
# Version: P-03
# Type: Main

#Inclusion de recursos
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
require_relative 'ShieldBooster'
require_relative 'ShotResult'
require_relative 'SpaceStation'
require_relative 'SuppliesPackage'
require_relative 'Weapon'
require_relative 'WeaponType'

#MODEL
module Deepspace
  #CLASS TEST
  class TestP3
    @@SEPARATOR = "\n/////////////////////////////////////////////////////////////////\n\n"

    private

    #Brief: Crea objetos loot para hacer el test
    def createLoot
      loot1 = Loot.new(1, 2, 3, 4, 5)
      loot2 = Loot.new(4, 5, 6, 7, 8)
      loot3 = Loot.new(7, 8, 9, 10, 11)

      loots = [loot1, loot2, loot3]
      return loots
    end

    #Brief: Crea objetos SuppliesPackage para hacer el test
    def createSuppliesPackage
      supplies1 = SuppliesPackage.new(2, 3, 5)
      supplies2 = SuppliesPackage.new(4, 5, 6)
      supplies3 = SuppliesPackage.new(7, 8, 9)

      supplies = [supplies1, supplies2, supplies3]
      return supplies
    end

    #Brief: Crea objetos Weapon para hacer el test
    def createWeapon
      weapon1 = Weapon.new("W1", WeaponType::LASER, 5)
      weapon2 = Weapon.new("W2", WeaponType::MISSILE, 7)
      weapon3 = Weapon.new("W3", WeaponType::PLASMA, 10)

      weapons = [weapon1, weapon2, weapon3]
      return weapons
    end

    #Brief: Crea objetos ShieldBooster para hacer el test
    def createShieldBooster
      shield1 = ShieldBooster.new("S1", 2.0, 10)
      shield2 = ShieldBooster.new("S2", 3.0, 20)
      shield3 = ShieldBooster.new("S3", 4.0, 25)

      shields = [shield1, shield2, shield3]
      return shields
    end

    #Brief: Crea objetos Hangar para hacer el test
    def createHangar
      hangar1 = Hangar.new(3)
      hangar2 = Hangar.new(5)
      hangar3 = Hangar.new(8)

      hangars = [hangar1, hangar2, hangar3]
      return hangars
    end

    #Brief: Crea objetos DamageNumeric para hacer el test
    def createDamageNumeric
      damageNumeric1 = Damage.newNumericWeapons(0, 0)
      damageNumeric2 = Damage.newNumericWeapons(2, 4)
      damageNumeric3 = Damage.newNumericWeapons(5, 7)

      damages = [damageNumeric1, damageNumeric2, damageNumeric3]
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

      dSpecific1 = Damage.newSpecificWeapons(array1, 0)
      dSpecific2 = Damage.newSpecificWeapons(array2, 1)
      dSpecific3 = Damage.newSpecificWeapons(array3, 2)
      dSpecific4 = Damage.newSpecificWeapons(array4, 3)
      dSpecific5 = Damage.newSpecificWeapons(array5, 0)
      dSpecific6 = Damage.newSpecificWeapons(array6, 5)

      damages = [dSpecific1, dSpecific2, dSpecific3, dSpecific4, dSpecific5, dSpecific6]
      return damages
    end

    #Brief: Crea objetos EnemyStarShip para hacer el test
    def createEnemyStarShip
      loot = createLoot
      damage1 = createDamageNumeric
      damage2 = createDamageSpecific

      enemy1 = EnemyStarShip.new("E1", 5, 6, loot[0], Damage.newCopy(damage1[0]))
      enemy2 = EnemyStarShip.new("E2", 10, 20, loot[1], Damage.newCopy(damage2[1]))
      enemy3 = EnemyStarShip.new("E3", 50, 100, loot[2], Damage.newCopy(damage2[4]))

      enemies = [enemy1, enemy2, enemy3]
      return enemies
    end

    #Brief: Crea objeto SpaceStation para hacer el test
    def createSpaceStation
      supplies = createSuppliesPackage

      return SpaceStation.new("Delorean", supplies[1])
    end

    #==========================================================================

    #Brief: Titulo de test
    def titleTest(index, object, section)
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
      @gameUniverse = GameUniverse.new
    end

    #==========================================================================

    public

    #Brief: Metodo de TEST
    #Param: array->Array de opciones
    def init(array)
      if array.include?(1)
        testSpaceStation
        puts @@SEPARATOR
      end

      if array.include?(2)
        testGameUniverse
        puts @@SEPARATOR
      end
    end

    #==========================================================================

    private

    #Brief: Test 9 -> TEST SPACESTATION
    def testSpaceStation
      #=============================================================
      #TESTS SPACESTATION
      # 1. TO_S
      # 2. DESCARTAR ELEMENTOS MONTADOS
      # 3. RECIBIR LOOT
      # 4. FIRE METODO
      # 5. PROTECTION METODO
      # 6. RECIBIR SHOT
      #=============================================================

      index = 1
      object = "SPACESTATION"
      section = "METODO TO_S"

      titleTest(index, object, section)

      @spaceStation.receiveHangar(@hangar[2])
      @spaceStation.hangar.maxElements.times { |i|
        @spaceStation.receiveWeapon(Weapon.newCopy(@weapon[i % 3]))
        @spaceStation.receiveShieldBooster(ShieldBooster.newCopy(@shieldBooster[i % 3]))
      }

      3.times {
        @spaceStation.mountWeapon(0)
        @spaceStation.mountShieldBooster(0)
      }

      puts "#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "DESCARTAR ELEMENTOS MONTADOS"

      titleTest(index, object, section)
      puts "--> ARMAS MONTADAS : #{@spaceStation.weapons.length}"
      puts "--> SHIELDS MONTADOS : #{@spaceStation.shieldBoosters.length}"

      puts "\n--> DESCARTANDO WEAPON[2]..."
      @spaceStation.discardWeapon(2)
      puts "--> ARMAS MONTADAS : #{@spaceStation.weapons.length}"

      puts "\n--> DESCARTANDO WEAPON[3]..."
      @spaceStation.discardWeapon(3)
      puts "--> ARMAS MONTADAS : #{@spaceStation.weapons.length}"

      puts "\n--> DESCARTANDO SHIELDBOOSTER[0]..."
      @spaceStation.discardShieldBooster(0)
      puts "--> SHIELDS MONTADOS : #{@spaceStation.shieldBoosters.length}"

      puts "\n--> DESCARTANDO SHIELDBOOSTER[4]..."
      @spaceStation.discardShieldBooster(4)
      puts "--> SHIELDS MONTADOS : #{@spaceStation.shieldBoosters.length}"

      puts "\n--> RECIBIENDO DAMAGE : \n#{@damageSpecific[1].to_s}"
      @spaceStation.setPendingDamage(Damage.newCopy(@damageSpecific[1]))
      puts "\n--> ESTADO ACTUAL SPACESTATION: \n#{@spaceStation.to_s}"

      puts "\n--> DESCARTANDO MISSILE..."
      @spaceStation.discardWeapon(1)
      puts "\n--> PENDING DAMAGE SPACESTATION: \n#{@spaceStation.pendingDamage}"

      puts "\n--> DESCARTANDO LASER..."
      @spaceStation.discardWeapon(0)
      puts "\n--> PENDING DAMAGE SPACESTATION: \n#{@spaceStation.pendingDamage}"

      puts "\n--> DESCARTANDO ESCUDO..."
      @spaceStation.discardShieldBooster(1)
      puts "\n--> ESTADO ACTUAL SPACESTATION: \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "RECIBIR LOOT"

      titleTest(index, object, section)

      loot = Loot.new(3, 3, 3, 0, 3)
      puts "--> LOOT A RECIBIR: \n#{loot.to_s}"
      puts "\n--> RECIBIENDO LOOT..."

      @spaceStation.setLoot(loot)
      puts "\n--> ESTADO ACTUAL SPACESTATION: \n#{@spaceStation.to_s}"

      puts "\n--> MONTANDO TODAS LAS ARMAS Y ESCUDOS..."
      @spaceStation.hangar.weapons.length.times {
        @spaceStation.mountWeapon(0)
      }
      @spaceStation.hangar.shieldBoosters.length.times {
        @spaceStation.mountShieldBooster(0)
      }
      puts "\n--> DESCARTANDO HANGAR..."
      @spaceStation.discardHangar

      puts "\n--> ESTADO ACTUAL SPACESTATION: \n#{@spaceStation.to_s}"

      puts "\n--> VOLVIENDO A RECIBIR MISMO LOOT..."
      @spaceStation.setLoot(loot)

      puts "\n--> ESTADO ACTUAL SPACESTATION: \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "METODO PROTECTION"

      titleTest(index, object, section)
      puts "--> ESTADO DE LOS ESCUDOS MONTADOS ACTUALMENTE: "
      @spaceStation.shieldBoosters.each { |shield|
        puts "#{shield.to_s}"
      }
      puts "\n--> UTILIZANDO METODO DE PROTECCION..."
      value = @spaceStation.protection

      puts "\n--> ESTADO DE LOS ESCUDOS MONTADOS TRAS PROTECTION: "
      @spaceStation.shieldBoosters.each { |shield|
        puts "#{shield.to_s}"
      }
      puts "\n--> VALOR DE PROTECCION USADO: #{value}"

      #=============================================================

      index += 1
      section = "METODO FIRE"

      titleTest(index, object, section)
      puts "--> ESTADO DE LAS ARMAS MONTADAS ACTUALMENTE: "
      @spaceStation.weapons.each { |weapon|
        puts "#{weapon.to_s}"
      }
      puts "\n--> UTILIZANDO METODO DE DISPARO..."
      value = @spaceStation.fire

      puts "\n--> ESTADO DE LAS ARMAS MONTADAS TRAS DISPARO "
      @spaceStation.weapons.each { |weapon|
        puts "#{weapon.to_s}"
      }

      puts "\n--> VALOR DE DISPARO USADO: #{value}"

      #=============================================================

      index += 1
      section = "RECIBIR SHOT"

      titleTest(index, object, section)
      puts "--> RECIBIENDO SHOT DE 50..."
      puts "--> RESULTADO: #{@spaceStation.receiveShot(50)}"

      puts "\n--> RECIBIENDO SHOT DE 100.000.000 ..."
      puts "--> RESULTADO: #{@spaceStation.receiveShot(100000000)}"
    end

    #Brief: Test 2 -> TEST GAMEUNIVERSE
    def testGameUniverse
      #=============================================================
      #TESTS GAMEUNIVERSE
      # 1. TO_S
      # 2. METODO INIT
      # 3. GESTION DE SPACESTATION ACTUAL
      # 4. METODO COMBAT
      # 5. METODO NEXTTURN
      #=============================================================

      index = 1
      object = "GAMEUNIVERSE"
      section = "METODO TO_S"

      @gameUniverse.init("Pablo")
      titleTest(index, object, section)
      puts "#{@gameUniverse.to_s}"

      #=============================================================

      index += 1
      section = "METODO INIT"

      titleTest(index, object, section)

      names = ["PlayerA", "PlayerB"]
      puts "--> JUGADORES:"
      names.each { |n| puts "- #{n}" }

      puts "\n--> INICIANDO GAME..."
      @gameUniverse.init(names)
      puts "--> ESTADO ACTUAL DEL JUEGO: \n#{@gameUniverse.to_s}"

      #=============================================================

      index += 1
      section = "GESTION DE SPACESTATION ACTUAL"

      titleTest(index, object, section)
      puts "--> ESTADO ACTUAL DEL JUEGO: #{@gameUniverse.state}"
      puts "--> MONTANDO TODOS LOS ELEMENTOS DE LOS QUE DISPONE LA ESTACION..."
      100.times { |i|
        @gameUniverse.mountWeapon(i)
        @gameUniverse.mountShieldBooster(i)
      }

      #=============================================================

      index += 1
      section = "METODO COMBAT"

      titleTest(index, object, section)
      puts "--> ESTADO ACTUAL DEL JUEGO: #{@gameUniverse.state}"
      puts "--> REALIZANDO COMBATE..."
      result = @gameUniverse.combat
      puts "\n--> RESULTADO DEL COMBATE: #{result}"
      puts "--> ESTADO ACTUAL DEL JUEGO #{@gameUniverse.state}"

      #=============================================================

      index += 1
      section = "METODO NEXTTURN"

      titleTest(index, object, section)
      puts "--> ESTADO ACTUAL DEL JUEGO: #{@gameUniverse.state}"

      value = @gameUniverse.nextTurn

      puts "--> SE PUEDE PASAR DE TURNO? : #{value}"

      if value == false
        puts "\n--> DESCARTANDO TODOS LOS ELEMENTOS MONTADOS DE LA ESTACION..."
        100.times { |i|
          @gameUniverse.discardWeapon(i)
          @gameUniverse.discardShieldBooster(i)
        }

        value = @gameUniverse.nextTurn
        puts "--> CASTIGO CUMPLIDO ? : #{value}"
      end

      puts "\n--> INFORMACION ACTUAL SOBRE EL JUEGO: \n#{@gameUniverse.to_s}"
    end

  end

  #CLASS
end #MODULE

#===========================================================
#INICIO DE TEST
#===========================================================

#Usa este array para indicar los test que quieres ejecutar
#TESTS Y SU CORRESPONDIENTE OPCION
# -> 1: Test SpaceStation
# -> 2: Test GameUniverse

#NOTA: Puedes transformar este rango por defecto en las opciones que tu
# quieras de la manera siguiente: [1,2,3,4,6,7,8,9]
array = (1..2)

#LANZADOR DE TEST DE PRACTICA
test = Deepspace::TestP3.new
test.init(array)

# File: TestP2.rb
# Brief: Test del programa
# Version: P-02
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
  class TestP2
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
        testLoot
        puts @@SEPARATOR
      end

      if array.include?(2)
        testSuppliesPackage
        puts @@SEPARATOR
      end

      if array.include?(3)
        testWeapon
        puts @@SEPARATOR
      end

      if array.include?(4)
        testShieldBooster
        puts @@SEPARATOR
      end

      if array.include?(5)
        testDice
        puts @@SEPARATOR
      end

      if array.include?(6)
        testHangar
        puts @@SEPARATOR
      end

      if array.include?(7)
        testDamage
        puts @@SEPARATOR
      end

      if array.include?(8)
        testEnemyStarShip
        puts @@SEPARATOR
      end

      if array.include?(9)
        testSpaceStation
        puts @@SEPARATOR
      end

      if array.include?(10)
        testGameUniverse
        puts @@SEPARATOR
      end
    end

    #==========================================================================

    private

    #Brief: Test 1 -> TEST LOOT
    def testLoot
      #=============================================================
      #TESTS LOOT:
      # 1. TO_S
      #=============================================================

      index = 1
      object = "LOOT"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@loot[0].to_s}"
    end

    #Brief: Test 2 -> TEST SUPPLIESPACKAGE
    def testSuppliesPackage
      #=============================================================
      #TESTS SUPPLIESPACKAGE:
      # 1. TO_S
      # 2. CONSTRUCTOR COPIA
      #=============================================================

      index = 1
      object = "SUPPLIESPACKAGE"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@suppliesPackage[0].to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@suppliesPackage[1].to_s}"
      suppliesCopy = SuppliesPackage.newCopy(@suppliesPackage[1])
      puts "\n--> OBJETO COPIADO [SUPPLIESCOPY] \n#{suppliesCopy.to_s}"
    end

    #Brief: Test 3 -> TEST WEAPON
    def testWeapon
      #=============================================================
      #TESTS WEAPON:
      # 1. TO_S
      # 2. CONSTRUCTOR COPIA
      # 3. METODO USEIT SIN GASTAR WEAPON
      # 4. METODO USEIT GASTANDO WEAPON
      #=============================================================

      index = 1
      object = "WEAPON"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@weapon[0].to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@weapon[1].to_s}"
      weaponCopy = Weapon.newCopy(@weapon[1])
      puts "\n--> OBJETO COPIADO [WEAPONCOPY] \n#{weaponCopy.to_s}"

      puts "\n--> MODIFICANDO OBJETO [WEAPONCOPY]..."
      weaponCopy.useIt
      puts "\n--> COMPROBANDO INTEGRIDAD DE LAS COPIAS..."
      puts "\n--> OBJETO ORIGINAL: \n#{@weapon[1].to_s}"
      puts "\n--> OBJETO COPIA: \n#{weaponCopy.to_s}"

      #=============================================================

      index += 1
      section = "METODO USEIT SIN GASTAR ARMA"

      titleTest(index, object, section)
      puts "--> WEAPON A USAR: \n#{@weapon[2].to_s}"
      puts "\n--> USANDO 4 VECES..."
      3.times {
        @weapon[2].useIt
      }
      puts "\n--> POWER DE USEIT: #{@weapon[2].useIt}"
      puts "--> WEAPON TRAS 4 USOS: \n#{@weapon[2].to_s}"

      #=============================================================

      index += 1
      section = "METODO USEIT GASTANDO ARMA"

      titleTest(index, object, section)
      puts "--> WEAPON A USAR: \n#{@weapon[2].to_s}"
      puts "\n--> USANDO 15 VECES..."
      14.times {
        @weapon[2].useIt
      }
      puts "\n--> POWER DE USEIT: #{@weapon[2].useIt}"
      puts "--> WEAPON TRAS 15 USOS: \n#{@weapon[2].to_s}"

    end

    #Brief: Test 4 -> TEST SHIELDBOOSTER
    def testShieldBooster
      #=============================================================
      #TESTS SHIELDBOOSTER
      # 1. TO_S
      # 2. CONSTRUCTOR COPIA
      # 3. METODO USEIT SIN GASTAR SHIELDBOOSTER
      # 4. METODO USEIT GASTANDO SHIELDBOOSTER
      #=============================================================

      index = 1
      object = "SHIELDBOOSTER"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@shieldBooster[0].to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@shieldBooster[1].to_s}"
      shieldCopy = ShieldBooster.newCopy(@shieldBooster[1])
      puts "\n--> OBJETO COPIADO [SHIELDCOPY] \n#{shieldCopy.to_s}"

      puts "\n--> MODIFICANDO OBJETO [SHIELDCOPY]..."
      shieldCopy.useIt
      puts "\n--> COMPROBANDO INTEGRIDAD DE LAS COPIAS..."
      puts "\n--> OBJETO ORIGINAL: \n#{@shieldBooster[1].to_s}"
      puts "\n--> OBJETO COPIA: \n#{shieldCopy.to_s}"

      #=============================================================

      index += 1
      section = "METODO USEIT SIN GASTAR ESCUDO"

      titleTest(index, object, section)
      puts "--> SHIELDBOOSTER A USAR: \n#{@shieldBooster[2].to_s}"
      puts "\n--> USANDO 20 VECES..."
      19.times {
        @shieldBooster[2].useIt
      }
      puts "\n--> POWER DE USEIT: #{@shieldBooster[2].useIt}"
      puts "--> SHIELDBOOSTER TRAS 4 USOS: \n#{@shieldBooster[2].to_s}"

      #=============================================================

      index += 1
      section = "METODO USEIT GASTANDO ESCUDO"

      titleTest(index, object, section)
      puts "--> SHIELDBOOSTER A USAR: \n#{@shieldBooster[2].to_s}"
      puts "\n--> USANDO 13 VECES..."
      12.times {
        @shieldBooster[2].useIt
      }
      puts "\n--> POWER DE USEIT: #{@shieldBooster[2].useIt}"
      puts "--> SHIELDBOOSTER TRAS 13 USOS: \n#{@shieldBooster[2].to_s}"
    end

    #Brief: Test 5 -> TEST DICE
    def testDice
      #=============================================================
      #TESTS DICE
      # 1. TO_S (10 ejecuciones)
      #=============================================================

      index = 1
      object = "DICE"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "--> EJECUTANDO 10 VECES DADO..."

      10.times { |i|
        puts "\n#{@dice.to_s}- STATIONMOVES ? : #{@dice.spaceStationMoves((i + 1) / 10)} \n- WHOSTARTS : PLAYER #{@dice.whoStarts(2)}"
      }
    end

    #Brief: Test 6 -> TEST HANGAR
    def testHangar
      #=============================================================
      #TESTS HANGAR
      # 1. TO_S
      # 2. INSERTAR ELEMENTOS EN HANGAR
      # 3. LLENAR HANGAR
      # 4. ELIMINAR ELEMENTOS DEL HANGAR
      # 5. ELIMINAR ELEMENTOS QUE NO EXISTEN DEL HANGAR
      # 6. CONSTRUCTOR DE COPIA
      #=============================================================

      index = 1
      object = "HANGAR"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@hangar[0].to_s}"

      #=============================================================

      index += 1
      section = "INSERTAR ELEMENTOS EN EL HANGAR"

      titleTest(index, object, section)
      puts "--> INSERTANDO WEAPON EN HANGAR: \n#{@weapon[0].to_s}\n"
      puts "* ESPACIO DISPONIBLE TRAS INSERTAR WEAPON --> #{@hangar[0].addWeapon(@weapon[0])}"
      puts "\n--> ESTADO DEL HANGAR TRAS LA INSERCION: \n#{@hangar[0].to_s}"

      puts "\n--> INSERTANDO SHIELDBOOSTER EN HANGAR: \n#{@shieldBooster[0].to_s}\n"
      puts "* ESPACIO DISPONIBLE TRAS INSERTAR SHIELD --> #{@hangar[0].addShieldBooster(@shieldBooster[0])}"
      puts "\n--> ESTADO DEL HANGAR TRAS LA INSERCION: \n#{@hangar[0].to_s}"

      #=============================================================

      index += 1
      section = "LLENAR HANGAR A SU MAX CAPACIDAD"

      titleTest(index, object, section)
      puts "--> INSERTANDO 10 WEAPONS EN EL HANGAR: \n#{@weapon[0].to_s}\n"
      10.times { |i|
        puts "\* ESPACIO DISPONIBLE TRAS INSERTAR WEAPON #{i + 1} --> #{@hangar[0].addWeapon(@weapon[0])}"
      }
      puts "\n--> ESTADO DEL HANGAR TRAS LA INSERCION: \n#{@hangar[0].to_s}"

      #=============================================================

      index += 1
      section = "ELIMINAR ELEMENTOS DEL HANGAR"

      titleTest(index, object, section)
      puts "--> ESTADO ACTUAL DEL HANGAR: \n#{@hangar[0].to_s}"
      puts "\n--> ELIMINANDO WEAPON[1] Y COPIANDO A VARIABLE [REMOVEDWEAPON]..."
      removedWeapon = @hangar[0].removeWeapon(1)
      puts "\n--> ARMA ELIMINADA [REMOVEDWEAPON]: \n#{removedWeapon.to_s}"

      puts "\n--> ELIMINANDO SHIELD[0] Y COPIANDO A VARIABLE [REMOVEDSHIELD]..."
      removedShield = @hangar[0].removeShieldBooster(0)

      puts "\n--> ESCUDO ELIMINADO [REMOVEDSHIELD]: \n#{removedShield.to_s}"

      #=============================================================

      index += 1
      section = "ELIMINAR ELEMENTOS QUE NO EXISTEN EN EL HANGAR"

      titleTest(index, object, section)
      puts "--> ESTADO ACTUAL DEL HANGAR: \n#{@hangar[0].to_s}"

      puts "\n--> ELIMINANDO WEAPON[5] Y COPIANDO A VARIABLE [REMOVEDWEAPON]..."
      removedWeapon = @hangar[0].removeWeapon(5)

      if removedWeapon.nil?
        puts "\n--> ARMA ELIMINADA [REMOVEDWEAPON]: Ninguna"
      else
        puts "\n--> ARMA ELIMINADA [REMOVEDWEAPON]: \n#{removedWeapon.to_s}"
      end

      puts "\n--> ELIMINANDO SHIELD[7] Y COPIANDO A VARIABLE [REMOVEDSHIELD]..."
      removedShield = @hangar[0].removeShieldBooster(7)

      if removedShield.nil?
        puts "\n--> ESCUDO ELIMINADO [REMOVEDSHIELD]: Ninguno"
      else
        puts "\n--> ESCUDO ELIMINADO [REMOVEDSHIELD]: \n#{removedShield.to_s}"
      end

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@hangar[0].to_s}"
      hangarCopy = Hangar.newCopy(@hangar[0])
      puts "\n--> OBJETO COPIADO [HANGARCOPY]: \n#{hangarCopy.to_s}"

      puts "\n--> MODIFICANDO OBJETO [HANGARCOPY]..."
      puts "\n--> INSERTANDO UN ESCUDO Y ELIMINANDO WEAPON[0] DE [HANGARCOPY]..."
      hangarCopy.removeWeapon(0)
      hangarCopy.addShieldBooster(@shieldBooster[1])

      puts "\n--> COMPROBANDO INTEGRIDAD DE LAS COPIAS..."
      puts "\n--> OBJETO ORIGINAL: \n#{@hangar[0].to_s}"
      puts "\n--> OBJETO COPIA: \n#{hangarCopy.to_s}"

      #=============================================================

    end

    #Brief: Test 7 -> TEST DAMAGE
    def testDamage
      #=============================================================
      #TESTS DAMAGE
      # 1. TO_S
      # 2. CONSTRUCTOR COPIA
      # 3. AJUSTE DAMAGE - OBJETO SIN EFECTO
      # 4. AJUSTE DAMAGE - SOLO EXISTEN SHIELDS
      # 5. AJUSTE DAMAGE - SOLO EXISTEN WEAPONS
      # 6. AJUSTE DAMAGE - SHIELDS Y WEAPONS
      #=============================================================

      index = 1
      object = "DAMAGE"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "--> DAMAGE NUMERIC WEAPONS: \n#{@damageNumeric[0].to_s}"
      puts "\n--> DAMAGE SPECIFIC WEAPONS: \n#{@damageSpecific[0].to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA [NUMERIC WEAPONS]"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@damageNumeric[1].to_s}"
      numericCopy = Damage.newCopy(@damageNumeric[1])
      puts "\n--> OBJETO COPIADO [NUMERICCOPY]: \n#{numericCopy.to_s}"

      puts "\n--> MODIFICANDO OBJETO [NUMERICCOPY]..."
      puts "--> ELIMINANDO UN ESCUDO Y 2 WEAPONS..."

      numericCopy.discardShieldBooster
      numericCopy.discardWeapon(nil)
      numericCopy.discardWeapon(nil)

      puts "\n--> COMPROBANDO INTEGRIDAD DE LAS COPIAS..."
      puts "\n--> OBJETO ORIGINAL: \n#{@damageNumeric[1].to_s}"
      puts "\n--> OBJETO COPIA: \n#{numericCopy.to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA [SPECIFIC WEAPONS]"

      titleTest(index, object, section)
      puts "--> OBJETO A COPIAR: \n#{@damageSpecific[2].to_s}"
      specificCopy = Damage.newCopy(@damageSpecific[2])
      puts "\n---> OBJETO COPIADO [SPECIFICCOPY]: \n#{specificCopy.to_s}"

      puts "\n--> MODIFICANDO OBJETO [SPECIFICCOPY]..."
      puts "--> ELIMINANDO UN ESCUDO Y 3 WEAPONS [LASER,MISSILE,PLASMA]..."

      specificCopy.discardShieldBooster
      specificCopy.discardWeapon(Weapon.new("REMOVED", WeaponType::LASER, 20))
      specificCopy.discardWeapon(Weapon.new("REMOVED", WeaponType::MISSILE, 20))
      specificCopy.discardWeapon(Weapon.new("REMOVED", WeaponType::PLASMA, 20))

      puts "\n--> COMPROBANDO INTEGRIDAD DE LAS COPIAS..."
      puts "\n--> OBJETO ORIGINAL: \n#{@damageSpecific[2].to_s}"
      puts "\n--> OBJETO COPIA: \n#{specificCopy.to_s}"

      #=============================================================

      index += 1
      section = "AJUSTE DAMAGE - SIN EFECTO"

      titleTest(index, object, section)
      puts "--> NUMERIC DAMAGE RECIBIDO: \n#{@damageNumeric[2].to_s}"

      collectionWeapons = Array.new
      collectionShields = Array.new

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s}"
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s}"

      damageAdjust = @damageNumeric[2].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      puts "\n\n--> SPECIFIC DAMAGE RECIBIDO: \n#{@damageSpecific[1].to_s}"

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s}"
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s}"

      damageAdjust = @damageSpecific[1].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      #=============================================================

      index += 1
      section = "AJUSTE DAMAGE - SOLO EXISTEN SHIELDS"

      titleTest(index, object, section)
      puts "--> NUMERIC DAMAGE RECIBIDO: \n#{@damageNumeric[1].to_s}"

      collectionWeapons = Array.new
      collectionShields = [ShieldBooster.newCopy(@shieldBooster[0]), ShieldBooster.newCopy(@shieldBooster[1]),
                           ShieldBooster.newCopy(@shieldBooster[2])]

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s}"
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each { |shield|
        puts "#{shield.to_s}"
      }

      damageAdjust = @damageNumeric[1].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      puts "\n\n--> SPECIFIC DAMAGE RECIBIDO: \n#{@damageSpecific[0].to_s}"

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s}"
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each { |shield|
        puts "#{shield.to_s}"
      }

      damageAdjust = @damageSpecific[0].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      #=============================================================

      index += 1
      section = "AJUSTE DAMAGE - SOLO EXISTEN WEAPONS"

      titleTest(index, object, section)
      puts "--> NUMERIC DAMAGE RECIBIDO: \n#{@damageNumeric[2].to_s}"

      collectionWeapons = [Weapon.newCopy(@weapon[1]), Weapon.newCopy(@weapon[1]), Weapon.newCopy(@weapon[2])]
      collectionShields = Array.new

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each { |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"

      damageAdjust = @damageNumeric[2].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      puts "\n\n--> SPECIFIC DAMAGE RECIBIDO: \n#{@damageSpecific[1].to_s}"

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each { |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"

      damageAdjust = @damageSpecific[1].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      #=============================================================

      index += 1
      section = "AJUSTE DAMAGE - SHIELDS Y WEAPONS"

      titleTest(index, object, section)
      puts "--> NUMERIC DAMAGE RECIBIDO: \n#{@damageNumeric[1].to_s}"

      collectionWeapons = [Weapon.newCopy(@weapon[0]), Weapon.newCopy(@weapon[1]), Weapon.newCopy(@weapon[2]), Weapon.newCopy(@weapon[2])]
      collectionShields = [ShieldBooster.newCopy(@shieldBooster[0]), ShieldBooster.newCopy(@shieldBooster[1]), ShieldBooster.newCopy(@shieldBooster[1]),
                           ShieldBooster.newCopy(@shieldBooster[2])]

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each { |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each { |shields|
        puts "#{shields.to_s}"
      }

      damageAdjust = @damageNumeric[2].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"

      puts "\n\n--> SPECIFIC DAMAGE RECIBIDO: \n#{@damageSpecific[2].to_s}"

      puts "\n--> COLECCION DE WEAPONS: #{collectionWeapons.to_s if collectionWeapons.empty?}"
      collectionWeapons.each { |weapons|
        puts "#{weapons.to_s}"
      }
      puts "--> COLECCION DE SHIELDS: #{collectionShields.to_s if collectionShields.empty?}"
      collectionShields.each { |shields|
        puts "#{shields.to_s}"
      }

      damageAdjust = @damageSpecific[2].adjust(collectionWeapons, collectionShields)
      puts "\n--> OBJETO DAMAGE AJUSTADO: \n#{damageAdjust.to_s}"
      puts "\n--> TIENE EFECTO?: #{!damageAdjust.hasNoEffect}"
    end

    #Brief: Test 8 -> TEST ENEMYSTARSHIP
    def testEnemyStarShip
      #=============================================================
      #TESTS ENEMYSTARSHIP
      # 1. TO_S
      # 2. CONSTRUCTOR COPIA
      # 3. RECEIVE SHOT METODO
      #=============================================================

      index = 1
      object = "ENEMYSTARSHIP"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@enemyStarShip[0].to_s}"

      #=============================================================

      index += 1
      section = "CONSTRUCTOR COPIA"

      titleTest(index, object, section)
      puts "--> OBJETO ORIGINAL: \n#{@enemyStarShip[1].to_s}"
      enemyCopy = EnemyStarShip.newCopy(@enemyStarShip[1])
      puts "--> OBJETO COPIA [ENEMYCOPY]: \n#{enemyCopy.to_s}"

      #=============================================================

      index += 1
      section = "RECEIVE SHOT"

      titleTest(index, object, section)
      puts "--> ENEMY: \n#{@enemyStarShip[2].to_s}"

      puts "\n--> SHOT RECEIVED [50] : RESIST? #{@enemyStarShip[2].receiveShot(50)}"
      puts "--> SHOT RECEIVED [1000] : RESIST? #{@enemyStarShip[2].receiveShot(1000)}"
    end

    #Brief: Test 9 -> TEST SPACESTATION
    def testSpaceStation
      #=============================================================
      #TESTS SPACESTATION
      # 1. TO_S
      # 2. RECIBIR OBJETOS : ELEMENTOS SIN HANGAR
      # 3. RECIBIR OBJETOS : HANGAR
      # 4. RECIBIR OBJETOS : ELEMENTOS CON HANGAR
      # 5. RECIBIR OBJETOS : SUPPLIESPACKAGE
      # 6. MONTAR ELEMENTOS A LA NAVE
      # 7. LIMPIAR ELEMENTOS MONTADOS SIN USOS
      # 8. RECIBIR DAMAGE
      # 9. DESCARTAR HANGAR
      #=============================================================

      index = 1
      object = "SPACESTATION"
      section = "METODO TO_S"

      titleTest(index, object, section)
      puts "#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "RECIBIR OBJETOS : ELEMENTOS SIN HANGAR"

      titleTest(index, object, section)
      if @spaceStation.hangar == nil
        puts "--> SPACESTATION POSEE HANGAR? : No"
      else
        puts "--> SPACESTATION POSEE HANGAR? : Si \n#{@spaceStation.hangar.to_s}"
      end

      puts "\n--> WEAPON A RECIBIR: \n#{@weapon[2].to_s}"
      puts "\n--> RECIBIENDO WEAPON..."
      puts "--> WEAPON RECIBIDO? : #{@spaceStation.receiveWeapon(@weapon[2])}"

      puts "\n--> SHIELDBOOSTER A RECIBIR: \n#{@shieldBooster[2].to_s}"
      puts "\n--> RECIBIENDO SHIELDBOOSTER..."
      puts "--> SHIELDBOOSTER RECIBIDO? : #{@spaceStation.receiveShieldBooster(@shieldBooster[2])}"

      #=============================================================

      index += 1
      section = "RECIBIR OBJETOS : HANGAR"

      titleTest(index, object, section)
      if @spaceStation.hangar == nil
        puts "--> SPACESTATION POSEE HANGAR? : No"
      else
        puts "--> SPACESTATION POSEE HANGAR? : Si \n#{@spaceStation.hangar.to_s}"
      end

      puts "\n--> HANGAR A RECIBIR: \n#{@hangar[1].to_s}"
      puts "\n--> RECIBIENDO HANGAR..."
      @spaceStation.receiveHangar(@hangar[1])

      if @spaceStation.hangar == nil
        puts "\n--> SPACESTATION POSEE HANGAR? : No"
      else
        puts "\n--> SPACESTATION POSEE HANGAR? : Si \n#{@spaceStation.hangar.to_s}"
      end

      #=============================================================

      index += 1
      section = "RECIBIR OBJETOS : ELEMENTOS CON HANGAR"

      titleTest(index, object, section)
      puts "\n--> WEAPON A RECIBIR: \n#{@weapon[2].to_s}"
      puts "\n--> RECIBIENDO WEAPON..."
      puts "--> WEAPON RECIBIDO? : #{@spaceStation.receiveWeapon(@weapon[2])}"

      puts "\n--> SHIELDBOOSTER A RECIBIR: \n#{@shieldBooster[2].to_s}"
      puts "\n--> RECIBIENDO SHIELDBOOSTER..."
      puts "--> SHIELDBOOSTER RECIBIDO? : #{@spaceStation.receiveShieldBooster(@shieldBooster[2])}"

      puts "\n--> RECIBIENDO 4 WEAPONS Y 3 SHIELDBOOSTERS..."
      10.times {
        @weapon[0].useIt
        @shieldBooster[0].useIt
      }

      7.times { |i|
        @spaceStation.receiveWeapon(Weapon.newCopy(@weapon[i % 3]))
        @spaceStation.receiveShieldBooster(ShieldBooster.newCopy(@shieldBooster[i % 3]))
      }

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "RECIBIR OBJETOS : SUPPLIESPACKAGE"

      titleTest(index, object, section)
      puts "--> PAQUETE DE SUMINISTROS A RECIBIR \n#{@suppliesPackage[1].to_s}"
      puts "\n--> RECIBIENDO PAQUETE..."
      @spaceStation.receiveSupplies(@suppliesPackage[1])

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "MONTAR ELEMENTOS A LA NAVE"

      titleTest(index, object, section)
      puts "--> MONTANDO WEAPON[1] EN LA NAVE..."
      weaponMounted = @spaceStation.mountWeapon(1)
      puts "--> WEAPON MONTADA ? : #{"Si" if !weaponMounted.nil?} #{"No" if weaponMounted.nil?}"

      puts "\n--> MONTANDO WEAPON[10] EN LA NAVE..."
      weaponMounted = @spaceStation.mountWeapon(10)
      puts "--> WEAPON MONTADA ? : #{"Si" if !weaponMounted.nil?} #{"No" if weaponMounted.nil?}"

      puts "\n--> MONTANDO SHIELDBOOSTER[1] EN LA NAVE..."
      shieldMounted = @spaceStation.mountShieldBooster(1)
      puts "--> SHIELD MONTADO ? : #{"Si" if !shieldMounted.nil?} #{"No" if shieldMounted.nil?}"

      puts "\n--> MONTANDO SHIELDBOOSTER[10] EN LA NAVE..."
      shieldMounted = @spaceStation.mountShieldBooster(10)
      puts "--> SHIELD MONTAD0 ? : #{"Si" if !shieldMounted.nil?} #{"No" if shieldMounted.nil?}"

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "LIMPIAR ELEMENTOS MONTADOS SIN USOS"

      titleTest(index, object, section)
      puts "--> MONTANDO WEAPON[0] Y SHIELDBOOSTER[0]..."
      @spaceStation.mountWeapon(0)
      @spaceStation.mountShieldBooster(0)

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      puts "\n--> LIMPIANDO ELEMENTOS SIN USOS..."
      @spaceStation.cleanUpMountedItems

      puts "\n--> ESTADO TRAS BORRAR ELEMENTOS SPACESTATION \n#{@spaceStation.to_s}"

      #=============================================================

      index += 1
      section = "RECIBIR DAMAGE"

      puts "--> DAMAGE A RECIBIR : \n#{@damageSpecific[0].to_s}"
      @spaceStation.setPendingDamage(@damageSpecific[0])

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      puts "\n--> ESTADO VALIDO SPACESTATION ? #{@spaceStation.validState}"

      puts "\n--> DAMAGE A RECIBIR : \n#{@damageSpecific[4].to_s}"
      @spaceStation.setPendingDamage(@damageSpecific[4])

      puts "\n--> ESTADO ACTUAL DE SPACESTATION \n#{@spaceStation.to_s}"

      puts "\n--> ESTADO VALIDO SPACESTATION ? #{@spaceStation.validState}"

      #=============================================================

      index += 1
      section = "DESCARTAR HANGAR"

      titleTest(index, object, section)
      puts "--> DESCARTANDO HANGAR..."
      @spaceStation.discardHangar

      if @spaceStation.hangar == nil
        puts "--> SPACESTATION POSEE HANGAR? : No"
      else
        puts "--> SPACESTATION POSEE HANGAR? : Si \n#{@spaceStation.hangar.to_s}"
      end

    end

    #Brief: Test 10 -> TEST GAMEUNIVERSE
    def testGameUniverse
      #=============================================================
      #TESTS GAMEUNIVERSE
      # 1. TO_S
      #=============================================================

      index = 1
      object = "GAMEUNIVERSE"
      section = "METODO TO_S"

      @gameUniverse.init("Pablo")
      titleTest(index, object, section)
      puts "#{@gameUniverse.to_s}"
    end

  end

  #CLASS
end #MODULE

#===========================================================
#INICIO DE TEST
#===========================================================

#Usa este array para indicar los test que quieres ejecutar
#TESTS Y SU CORRESPONDIENTE OPCION
# ->  1: Test Loot
# ->  2: Test SuppliesPackage
# ->  3: Test Weapon
# ->  4: Test ShieldBooster
# ->  5: Test Dice
# ->  6: Test Hangar
# ->  7: Test Damage
# ->  8: Test EnemyStarShip
# ->  9: Test SpaceStation
# -> 10: Test GameUniverse

#NOTA: Puedes transformar este rango por defecto en las opciones que tu
# quieras de la manera siguiente: [1,2,3,4,6,7,8,9]
array = (1..10)

#LANZADOR DE TEST DE PRACTICA
test = Deepspace::TestP2.new
test.init(array)

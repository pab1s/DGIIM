/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

import java.util.ArrayList;

/**
 *
 * @author Angel Olmedo & Pablo Olivares
 */
public class GameUniverse {
    private static final int WIN = 10;
    
    private int currentStationIndex;
    private int turns;
    private boolean haveSpaceCity;
    
    private GameStateController gameState;
    private EnemyStarShip currentEnemy;
    private ArrayList<SpaceStation> spaceStations = new ArrayList<>();
    private SpaceStation currentStation;
    private Dice dice;
    
    private void makeStationEfficient() {
        if (dice.extraEfficiency()) {
            currentStation = new BetaPowerEfficientSpaceStation(currentStation);
        } else {
            currentStation = new PowerEfficientSpaceStation(currentStation);
        }
    }
    
    private void createSpaceCity() {
        ArrayList<SpaceStation> rest = new ArrayList<>();
        
        if (!haveSpaceCity) {
            for (int i=0; i<spaceStations.size()-1; i++) {
                if (currentStationIndex != i) {
                    rest.add(spaceStations.get(i));
                }
            }    
            currentStation = new SpaceCity(currentStation, rest);
            spaceStations.set(currentStationIndex, currentStation);
            haveSpaceCity = true;
        }
    }
            
    public GameUniverse(){
        gameState = new GameStateController();
        turns = 0;
        dice = new Dice();
        currentStationIndex = 0;
        haveSpaceCity = false;
    }
    
    public CombatResult combat(SpaceStation station, EnemyStarShip enemy){
        GameCharacter ch = dice.firstShot();
        boolean enemyWins;
        float fire;
        ShotResult result;
        CombatResult combatResult;
        
        if(ch==GameCharacter.ENEMYSTARSHIP){
            fire = enemy.fire();
            result = station.receiveShot(fire);
            
            if(result==ShotResult.RESIST){
                fire = station.fire();
                result = enemy.receiveShot(fire);
                enemyWins = (result==ShotResult.RESIST);
            }else{
                enemyWins = true;
            }
            
        }else{
            fire = station.fire();
            result = enemy.receiveShot(fire);
            enemyWins = (result==ShotResult.RESIST);
        }
        
        if(enemyWins){
            float s = station.getSpeed();
            boolean moves = dice.spaceStationMoves(s);
            
            if(!moves){
                Damage damage = enemy.getDamage();
                station.setPendingDamage(damage);
                combatResult = CombatResult.ENEMYWINS;
            }else{
                station.move();
                combatResult = CombatResult.STATIONESCAPES;
            }
        }else{
            Loot aLoot = enemy.getLoot();
            Transformation r = station.setLoot(aLoot);
            
            if (r == Transformation.GETEFFICIENT) {
                makeStationEfficient();
                combatResult = CombatResult.STATIONWINSANDCONVERTS;
            } else if (r == Transformation.SPACECITY) {
                createSpaceCity();
                combatResult = CombatResult.STATIONWINSANDCONVERTS;
            } else {
                combatResult = CombatResult.STATIONWINS;
            }
        }
        
        gameState.next(turns, spaceStations.size());
        
        return combatResult;
    }
    
    public CombatResult combat(){
        GameState state = gameState.getState();
        if((state == GameState.BEFORECOMBAT) || (state == GameState.INIT))
            return combat(currentStation, currentEnemy);
        else
            return CombatResult.NOCOMBAT;
    }
    
    public void discardHangar(){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.discardHangar();
    }
    
    public void discardShieldBooster(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.discardShieldBooster(i);
    }
    
    public void discardShieldBoosterInHangar(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.discardShieldBoosterInHangar(i);
    }
    
    public void discardWeapon(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.discardWeapon(i);
    }
    
    public void discardWeaponInHangar(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.discardWeaponInHangar(i);
    }
    
    public GameState getState(){
        return gameState.getState();
    }
    
    public GameUniverseToUI getUIversion(){
        return new GameUniverseToUI(this.currentStation,this.currentEnemy);
    }
    
    public boolean haveAWinner(){
        return (currentStation.getNMedals() >= WIN);
    }
    
    public void init(ArrayList<String> names){
        GameState state = gameState.getState();
        
        if(state==GameState.CANNOTPLAY){
            CardDealer  dealer = CardDealer.getInstance();
            
            for(int i=0; i<names.size(); i++){
                SuppliesPackage supplies = dealer.nextSuppliesPackage();
                SpaceStation station = new SpaceStation(names.get(i), supplies);
                
                spaceStations.add(station);
                int nh = dice.initWithNHangars();
                int nw = dice.initWithNWeapons();
                int ns = dice.initWithNShields();
                
                Loot lo = new Loot(0, nw, ns, nh, 0);
                station.setLoot(lo);
            }
            
            currentStationIndex = dice.whoStarts(names.size());
            currentStation = spaceStations.get(currentStationIndex);
            currentEnemy = dealer.nextEnemy();
            gameState.next(turns, spaceStations.size());
        }
    }
    
    public void mountShieldBooster(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.mountShieldBooster(i);
    }
    
    public void mountWeapon(int i){
        if((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            currentStation.mountWeapon(i);
    }
    
    public boolean nextTurn(){
        GameState state = gameState.getState();
        
        if(state == GameState.AFTERCOMBAT){
            boolean stationState = currentStation.validState();
            
            if(stationState){
                currentStationIndex = (currentStationIndex+1)%spaceStations.size();
                turns++;
                currentStation = spaceStations.get(currentStationIndex);
                currentStation.cleanUpMountedItems();
                CardDealer dealer = CardDealer.getInstance();
                currentEnemy = dealer.nextEnemy();
                gameState.next(turns, spaceStations.size());
                return true;
            }
            return false;
        }
        return false; 
    }
    
    public String toString(){
        String finalString, cStI, trns, gS, cE, sSt, cSt, dc;
        
        cStI = "CURRENTSTATIONINDEX: " + currentStationIndex + "\n";
        trns = "TURNS: " + turns + "\n";
        gS = "GAMESTATE: " + gameState.getState() + "\n";
        
        cE = "CURRENTENEMY: \n";
        if(currentEnemy != null)
            cE += currentEnemy.toString() + "\n";
        else
            cE += " none\n";
        
        sSt = "SPACESTATIONS: \n" + spaceStations.toString();
        
        cSt = "CURRENSTATION: \n";
        if(currentStation != null)
            cSt += currentStation.toString() + "\n";
        else
            cE += " none\n";
        
        dc = "DICE: \n" + dice.toString();
        
        finalString = cStI + trns + gS + cE + sSt + cSt + dc;
        
        
        return finalString;
    }
    
}

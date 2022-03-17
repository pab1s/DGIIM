/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

/**
 *
 * @author Angel Olmedo & Pablo Olivares
 */
public class BetaPowerEfficientSpaceStation extends PowerEfficientSpaceStation {
    private static final float EXTRAEFFICIENCY = 1.2f;
    Dice dice;
    
    public BetaPowerEfficientSpaceStation(SpaceStation station) {
        super(station);
        dice = new Dice();
    }
    
    @Override
    public float fire(){
        if(dice.extraEfficiency())
            return super.fire()*EXTRAEFFICIENCY;
        
        return super.fire();
    }
    
    @Override
    public Transformation setLoot(Loot loot){
           super.setLoot(loot);
           return Transformation.NOTRANSFORM;
    }
    
    @Override
    public BetaPowerEfficientSpaceStationToUI getUIversion(){
        return new BetaPowerEfficientSpaceStationToUI(this);
    }
}

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
public class SpaceCity extends SpaceStation {
    private SpaceStation base;
    private ArrayList<SpaceStation> collaborators;
    
    public SpaceCity(SpaceStation base, ArrayList<SpaceStation> rest) {
        super(base);
        this.base = base;
        collaborators = new ArrayList<>(rest);
    }
    
    public ArrayList<SpaceStation> getCollaborators() {
        return collaborators;
    }
    
    @Override
    public float fire() {
        float factor = super.fire();
        
        for(SpaceStation station : collaborators) {
            factor += station.fire();
        }
        
        return factor;
    }
    
    @Override
    public float protection() {
        float factor = super.protection();
        
        for(SpaceStation station : collaborators) {
            factor += station.protection();
        }
        
        return factor;
    }
    
    @Override
    public Transformation setLoot(Loot loot) {
        super.setLoot(loot);
        return Transformation.NOTRANSFORM;
    }
    
    @Override
    public SpaceCityToUI getUIversion(){
        return new SpaceCityToUI(this);
    }
    
    @Override
    public String toString(){
        String finalString;
        String hb = "* ESTACION BASE: \n";
        String bs = base.toString();
        
        String hc = "\n* COLLABORATORS: \n";
        String c = collaborators.get(0).toString();
        
        for(int i=1; i<collaborators.size(); i++){
            c += collaborators.get(i).toString();
        }
        
        finalString = hb + bs + hc + c;
                
        return finalString;
    }
}

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
public class ShieldBooster implements CombatElement {
    private String name;
    private float boost;
    private int uses;
    
    ShieldBooster(String name, float boost, int uses){
        this.name = name;
        this.boost = boost;
        this.uses = uses;
    }
    
    ShieldBooster(ShieldBooster s){
        name = s.name;
        boost = s.boost;
        uses = s.uses;
    }
    
    float getBoost(){
        return boost;
    }
    
    @Override
    public final int getUses(){
        return uses;
    }
    
    @Override
    public final float useIt(){
        if(uses>0){
            uses = uses-1;
            return uses;
        }else
            return 0;
    }
    
    public ShieldToUI getUIversion(){
        return new ShieldToUI(this);
    }
    
    public String toString(){
        String finalString, nm, bst, us;
       
        nm = "NAME: " + name + "\n";
        bst = "BOOST: " + boost + "\n";
        us = "USES: " + uses + "\n";
        
        finalString = nm + bst + us;
        
        return finalString;
    }
    
}

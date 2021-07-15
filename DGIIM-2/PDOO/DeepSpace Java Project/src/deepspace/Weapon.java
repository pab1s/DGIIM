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
public class Weapon implements CombatElement {
    private String name;
    private WeaponType type;
    private int uses;
    
    Weapon(String name, WeaponType type, int uses){
        this.name = name;
        this.type = type;
        this.uses = uses;
    }
    
    Weapon(Weapon w){
        name = w.name;
        type = w.type;
        uses = w.uses;
    }
    
    WeaponType getType(){
        return type;
    }
    
    @Override
    public final int getUses(){
        return uses;
    }
    
    float power(){
        return type.getPower();
    }
    
    @Override
    public final float useIt(){
        if(uses>0){
            uses--;
            return uses;
        }else
            return 1;
    }
    
    public WeaponToUI getUIversion(){
        return new WeaponToUI(this);
    }
    
    public String toString(){
        String finalString, nm, wT, us, pw;
        
        nm = "NAME: " + name + "\n";
        wT = "TYPE: " + type + "\n";
        us = "USES: " + uses + "\n";
        pw = "POWER: " + power() + "\n";
        
        
        finalString = nm + wT + pw + us;
        
        return finalString;
    }
}

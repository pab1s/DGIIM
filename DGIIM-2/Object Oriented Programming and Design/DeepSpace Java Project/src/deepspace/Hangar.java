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
public class Hangar {
    private int maxElements;
    
    private ArrayList<Weapon> weapons = new ArrayList<>();
    private ArrayList<ShieldBooster> shieldBoosters = new ArrayList<>();
    
    Hangar(int capacity){
        maxElements = capacity;
    }
    
    Hangar(Hangar h){
        maxElements = h.maxElements;
        for(Weapon w : h.weapons){
            weapons.add(w);
        }
        for(ShieldBooster s: h.shieldBoosters){
            shieldBoosters.add(s);
        }
    }
    
    HangarToUI getUIversion(){
        return new HangarToUI(this);
    }
    
    private boolean spaceAvailable(){
        return ((weapons.size() + shieldBoosters.size()) < maxElements);
    }
    
    public boolean addWeapon(Weapon w){
        if(spaceAvailable()){
            weapons.add(w);
            return true;
        }else
            return false;
    }
    
    public boolean addShieldBooster(ShieldBooster s){
        if(spaceAvailable()){
            shieldBoosters.add(s);
            return true;
        }else
            return false;
    }
    
    public int getMaxElements(){
        return maxElements;
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return shieldBoosters;
    }
    
    public ArrayList<Weapon> getWeapons(){
        return weapons;
    }
    
    public ShieldBooster removeShieldBooster(int s){
        if(s>0 && s<shieldBoosters.size())
            return shieldBoosters.remove(s);
        else
            return null;
    }
    
    public Weapon removeWeapon(int w){
        if(w>=0 && w<weapons.size())
            return weapons.remove(w);
        else
            return null;
    }
    
    public String toString(){
        String finalString, mEl, wpns, shls;
        
        mEl = "MAXELEMENTS IN HANGAR: " + maxElements + "\n";
        
        wpns = "WEAPONS IN HANGAR: \n";
        if(weapons == null || weapons.isEmpty())
            wpns += " none\n";
        else
            for(Weapon w : weapons)
                wpns += " " +w.toString();
        
        shls = "SHIELDBOOSTERS IN HANGAR: \n";
        if(shieldBoosters == null || shieldBoosters.isEmpty())
            shls += " none\n";
        else
            for(ShieldBooster sb : shieldBoosters)
                shls += " " +sb.toString();
        
        finalString = mEl + wpns + shls;
        
        return finalString;
    }
    
}

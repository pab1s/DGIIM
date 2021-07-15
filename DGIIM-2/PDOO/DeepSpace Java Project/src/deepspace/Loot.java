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
public class Loot {
    private int nSupplies, nWeapons, nShields, nHangars, nMedals;
    private boolean efficient, spaceCity;
    
    Loot(int nSupplies, int nWeapons, int nShields, int nHangars, int nMedals){
        this.nSupplies = nSupplies;
        this.nWeapons = nWeapons;
        this.nShields = nShields;
        this.nHangars = nHangars;
        this.nMedals = nMedals;
        this.efficient = false;
        this.spaceCity = false;
    }
    
    Loot(int nSupplies, int nWeapons, int nShields, int nHangars, int nMedals, boolean ef, boolean city){
        this.nSupplies = nSupplies;
        this.nWeapons = nWeapons;
        this.nShields = nShields;
        this.nHangars = nHangars;
        this.nMedals = nMedals;
        this.efficient = ef;
        this.spaceCity = city;
    }
    
    public int getNSupplies(){
        return this.nSupplies;
    }
    
    public int getNWeapons(){
        return this.nWeapons;
    }
    
    public int getNShields(){
        return this.nShields;
    }
    
    public int getNHangars(){
        return this.nHangars;
    }
    
    public int getNMedals(){
        return this.nMedals;
    }
    
    public boolean getEfficient(){
        return this.efficient;
    }
    
    public boolean spaceCity(){
        return this.spaceCity;
    }
    
    public LootToUI getUIversion(){
        return new LootToUI(this);
    }
    
    public String toString(){
        String finalString, nS, nW, nSh, nH, nM, ef, city;
       
        nS = "NSUPPLIES: " + nSupplies + "\n";
        nW = "NWEAPONS: " + nWeapons + "\n";
        nSh = "NSHIELDS: " + nShields + "\n";
        nH = "NHANGARS: " + nHangars + "\n";
        nM = "NMEDALS: " + nMedals + "\n";
        ef = "EFFICIENT: " + efficient + "\n";
        city = "SPACECITY: " + spaceCity + "\n";
        
        finalString = nS + nW + nSh + nH + nM + ef + city;
        
        return finalString;
    }
}

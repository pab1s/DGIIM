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
public class SuppliesPackage {
    private float ammoPower;
    private float fuelUnits;
    private float shieldPower;
    
    SuppliesPackage(float ammoPower, float fuelUnits, float shieldPower){
        this.ammoPower= ammoPower;
        this.fuelUnits = fuelUnits;
        this.shieldPower = shieldPower;
    }
    
    SuppliesPackage(SuppliesPackage s){
        this.ammoPower = s.getAmmoPower();
        this.fuelUnits = s.getFuelUnits();
        this.shieldPower = s.getShieldPower();
    }
    
    float getAmmoPower(){
        return this.ammoPower;
    }
    
    float getFuelUnits(){
        return this.fuelUnits;
    }
    
    float getShieldPower(){
        return this.shieldPower;
    }
    
    public String toString(){
        String finalString, aP, fU, sP;
        
        aP = "AMMOPOWER: " + ammoPower + "\n";
        fU = "FUELUNITS: " + fuelUnits + "\n";
        sP = "SHIELDPOWER: " + shieldPower + "\n";
        
        finalString = aP + fU + sP;
        
        return finalString;
    }
        
}

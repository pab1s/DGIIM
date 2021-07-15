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
public enum WeaponType {
    LASER(2.0f), 
    MISSILE(3.0f), 
    PLASMA(4.0f);
    
    private final float power;
    
    WeaponType(float power){
        this.power = power;
    }
    
    public float getPower(){
        return power;
    }
}

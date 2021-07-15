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
public class EnemyStarShip implements SpaceFighter{
    private float ammoPower;
    private String name;
    private float shieldPower;
    private Loot loot;
    private Damage damage;
    
    EnemyStarShip(String n, float a, float s, Loot l, Damage d){
        name = n;
        ammoPower = a;
        shieldPower = s;
        loot = l;
        damage = d;
    }
    
    EnemyStarShip(EnemyStarShip e){
        name = e.name;
        ammoPower = e.ammoPower;
        shieldPower = e.shieldPower;
        loot = e.loot;
        damage = e.damage;
    }
    
    public float getAmmoPower(){
        return ammoPower;
    }
    
    public Damage getDamage(){
        return damage;
    }
    
    public Loot getLoot(){
        return loot;
    }
    
    public String getName(){
        return name;
    }
    
    public float getShieldPower(){
        return shieldPower;
    }
    
    @Override
    public float fire(){
        return ammoPower;
    }
    
    @Override
    public float protection(){
        return shieldPower;
    }
    
    @Override
    public ShotResult receiveShot(float shot){
        if(shot > shieldPower)
            return ShotResult.DONOTRESIST;
        else
            return ShotResult.RESIST;
    }
    
    EnemyToUI getUIversion(){
        return new EnemyToUI(this);
    }
    
    public String toString(){
        String finalString, aP, nme, sP, lt, dm;
        
        nme = "NAME: " + name + "\n";
        aP = "AMMOPOWER: " + ammoPower + "\n";
        sP = "SHIELDPOWER: " + shieldPower + "\n";
        
        lt = "LOOT: \n";
        if(loot == null)
            lt += "None\n";
        else 
            lt += loot.toString();
        
        dm = "DAMAGE: \n";
        if(damage == null)
            dm += "None\n";
        else
            dm += damage.toString() + "\n";
        
        finalString = nme + aP + sP + lt + dm;
        
        return finalString;
    }
    
}

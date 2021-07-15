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
public class SpaceStation implements SpaceFighter {
    private static final float MAXFUEL = 100f;
    private static final float SHIELDLOSSPERUNITSHOT = 0.1f;
    
    private float ammoPower;
    private float fuelUnits;
    private String name;
    private int nMedals;
    private float shieldPower;
    
    private Damage pendingDamage;
    private ArrayList<Weapon> weapons = new ArrayList<>();
    private ArrayList<ShieldBooster> shieldBoosters = new ArrayList<>();
    private Hangar hangar;
    
    
    private void assignFuelValue(float f){
        if(MAXFUEL < f)
            fuelUnits = MAXFUEL;
        else
            fuelUnits = f;
    }
    
    private void cleanPendingDamage(){
        if(pendingDamage.hasNoEffect())
            pendingDamage = null;
    }
    
    public SpaceStation(String n, SuppliesPackage supplies){
        name = n;
        ammoPower = supplies.getAmmoPower();
        shieldPower = supplies.getShieldPower();
        nMedals = 0;
        pendingDamage = null;
        
        assignFuelValue(supplies.getFuelUnits());
    }
    
    public SpaceStation(SpaceStation station) {
        name = station.name;
        ammoPower = station.ammoPower;
        shieldPower = station.shieldPower;
        nMedals = station.nMedals;
        pendingDamage = station.pendingDamage;
        hangar = station.hangar;
        
        assignFuelValue(station.fuelUnits);
        
        for(Weapon w : station.weapons){
            weapons.add(w);
        }
        for(ShieldBooster s : station.shieldBoosters){
            shieldBoosters.add(s);
        }
    }
    
    public void cleanUpMountedItems(){
        ArrayList<Weapon> weaponsWithoutUses = new ArrayList<>();
        ArrayList<ShieldBooster> shieldWithoutUses = new ArrayList<>();       
        
        for(Weapon w: weapons)
            if (w.getUses() == 0)
                weaponsWithoutUses.add(w);
        
        for(ShieldBooster s: shieldBoosters)
            if(s.getUses() == 0)
                shieldWithoutUses.add(s);
        
        for(Weapon w: weaponsWithoutUses)
            weapons.remove(w);
        
        for(ShieldBooster s: shieldWithoutUses)
            shieldBoosters.remove(s);
        
    }
    
    public void discardHangar(){
        hangar = null;
    }
    
    public void discardShieldBooster(int i){
        int size = shieldBoosters.size();
        
        if( (i >= 0) && (i < size)){
            shieldBoosters.remove(i);
            
            if(pendingDamage != null){
                pendingDamage.discardShieldBooster();
                cleanPendingDamage();
            }
        }
    }
    
    public void discardShieldBoosterInHangar(int i){
        if(hangar != null)
            hangar.removeShieldBooster(i);
    }
    
    public void discardWeapon(int i){
        int size = weapons.size();
        
        if( (i >= 0) && (i < size)){
            Weapon w = weapons.remove(i);
            
            if(pendingDamage != null){
                pendingDamage.discardWeapon(w);
                cleanPendingDamage();
            }
        }
    }
    
    public void discardWeaponInHangar(int i){
        if(hangar != null)
            hangar.removeWeapon(i);
    }
    
    public float getAmmoPower(){
        return ammoPower;
    }
    
    public float getFuelUnits(){
        return fuelUnits;
    }
    
    public Hangar getHangar(){
        return hangar;
    }
    
    public String getName(){
        return name;
    }
    
    public int getNMedals(){
        return nMedals;
    }
    
    public Damage getPendingDamage(){
        return pendingDamage;
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return shieldBoosters;
    }
    
    public float getShieldPower(){
        return shieldPower;
    }
    
    public float getSpeed(){
        return (fuelUnits/MAXFUEL);
    }
    
    public ArrayList<Weapon> getWeapons(){
        return weapons;
    }
    
    public void setPendingDamage(Damage d){
        pendingDamage = d.adjust(weapons, shieldBoosters);
    }
    
    public void mountShieldBooster(int i){
        if(hangar != null){
            ShieldBooster shieldBooster = hangar.removeShieldBooster(i);
            if(shieldBooster != null)
                shieldBoosters.add(shieldBooster);
        }
    }
    
    public void mountWeapon(int i){
        if(hangar != null){
            Weapon weapon = hangar.removeWeapon(i);
            if(weapon != null)
                weapons.add(weapon);
        }
    }
    
    public void move(){
        fuelUnits -= getSpeed();
        
        if(fuelUnits < 0)
            fuelUnits = 0;
    }
    
    @Override
    public float fire(){
        int size = weapons.size();
        float factor = 1;
        
        for(int i=0; i<size; i++){
            Weapon w = weapons.get(i);
            factor*= w.useIt();
        }
        
        return ammoPower*factor;
    }
    
    @Override
    public float protection(){
        int size = shieldBoosters.size();
        float factor = 1;
        
        for(int i=0; i<size; i++){
            ShieldBooster s = shieldBoosters.get(i);
            factor *= s.useIt();
        }
        
        return shieldPower*factor;
    }
    
    public void receiveHangar(Hangar h){
        if(hangar == null)
            hangar = h;
    }
    
    public boolean receiveShieldBooster(ShieldBooster s){
        if(hangar != null)
            return hangar.addShieldBooster(s);
        else
            return false;
    }
    
    @Override
    public ShotResult receiveShot(float shot){
        float myProtection = protection();
        
        if(myProtection>=shot){
            shieldPower -=SHIELDLOSSPERUNITSHOT*shot;
            shieldPower = Math.max(0.0f, shieldPower);
            return ShotResult.RESIST;
        }
        else{
            shieldPower = 0.0f;
            return ShotResult.DONOTRESIST;
        }
    }
    
    public void receiveSupplies(SuppliesPackage s){
        ammoPower += s.getAmmoPower();
        shieldPower += s.getShieldPower();
        fuelUnits += s.getFuelUnits();
        
        if(fuelUnits > MAXFUEL)
            fuelUnits = MAXFUEL;
    }
    
    public boolean receiveWeapon(Weapon w){
        if(hangar != null)
            return hangar.addWeapon(w);
        else
            return false;
    }
    
    public Transformation setLoot(Loot loot){
        CardDealer dealer = CardDealer.getInstance();
        
        int h = loot.getNHangars();
        if(h>0){
            hangar = dealer.nextHangar();
            receiveHangar(hangar);
        }
        
        int elements = loot.getNSupplies();
        for(int i=0; i<elements; i++){
            SuppliesPackage sup = dealer.nextSuppliesPackage();
            receiveSupplies(sup);
        }
        
        elements = loot.getNWeapons();
        for(int i=0; i<elements; i++){
            Weapon weap = dealer.nextWeapon();
            receiveWeapon(weap);
        }
        
        elements = loot.getNShields();
        for(int i=0; i<elements; i++){
            ShieldBooster sh = dealer.nextShieldBooster();
            receiveShieldBooster(sh);
        }
        
        int medals = loot.getNMedals();
        nMedals += medals;
        
        if (loot.getEfficient()) {
            return Transformation.GETEFFICIENT;
        } else if (loot.spaceCity()) {
            return Transformation.SPACECITY;
        } else {
            return Transformation.NOTRANSFORM;
        }
    }
    
    public boolean validState(){
        return (pendingDamage == null || pendingDamage.hasNoEffect());
    }
        
    public SpaceStationToUI getUIversion(){
        return new SpaceStationToUI(this);
    }    
    
    public String toString(){
        String finalString, nm, aP, fU, sP, pD, nM, wpns, shlds, hng;
        
        nm = "NAME: " + name + "\n";
        aP = "AMMOPOWER: " + ammoPower + "\n";
        fU = "FUELUNITS: " + fuelUnits + "\n";
        sP = "SHIELDPOWER: " + shieldPower + "\n";
        
        pD = "\nPENDINGDAMAGE: \n";
        if(pendingDamage == null)
            pD += " none\n";
        else
            pD += pendingDamage.toString();
        
        nM = "NMEDALS: " + nMedals + "\n";
        
        wpns = "\nWEAPONS MOUNTED: \n";
        if(weapons == null || weapons.isEmpty())
            wpns += " none\n";
        else
            for(Weapon w : weapons)
                wpns += w.toString();
        
        shlds = "\nSHIELDBOOSTERS MOUNTED: \n";
        if(shieldBoosters == null || shieldBoosters.isEmpty())
            shlds += " none\n";
        else
            for(ShieldBooster sB : shieldBoosters)
                shlds += sB.toString();
        
        hng = "HANGAR: \n";
        if(hangar == null)
            hng += " none\n";
        else
            hng += hangar.toString();
        
        finalString = nm + aP + fU + sP + pD + nM + wpns + shlds + hng;
        
        return finalString;
    }
    
}

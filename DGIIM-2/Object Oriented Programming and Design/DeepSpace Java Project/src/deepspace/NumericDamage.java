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
public class NumericDamage extends Damage {
    private int nWeapons;
    
    public NumericDamage() {
        super();
        nWeapons = 0;
    }
    
    public NumericDamage(int w, int s) {
        super(s);
        nWeapons = w;
    }
    
    public NumericDamage(NumericDamage nd) {
        super(nd);
        nWeapons = nd.nWeapons;
    }

    public int getNWeapons() {
        return nWeapons;
    }
    
    @Override
    public void discardWeapon(Weapon w) {
        if (nWeapons > 0) {
            nWeapons--;
        }
    }

    @Override
    public NumericDamage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s) {
        int retNShields = Math.min(nShields, s.size());
        int retNWeapons = Math.min(nWeapons, w.size());
        return new NumericDamage(retNWeapons, retNShields);
    }
       
    @Override
    public boolean hasNoEffect() {
        return (super.hasNoEffect() && (nWeapons == 0));
    }
    
    @Override
    public NumericDamageToUI getUIversion() {
        return new NumericDamageToUI(this);
    }

    @Override
    public String toString() {
        String finalString = super.toString();
        String nW = "NWEAPONS: " + nWeapons + "\n";

        finalString += nW;

        return finalString;
    }
}

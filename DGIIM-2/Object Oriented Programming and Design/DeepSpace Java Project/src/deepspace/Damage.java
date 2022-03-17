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
public abstract class Damage {

    protected int nShields;
    
    public Damage() {
        nShields = 0;
    }

    public Damage(int s) {
        nShields = s;
    }

    public Damage(Damage d) {
        nShields = d.nShields;
    }

    public abstract Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s);

    public void discardShieldBooster() {
        if (nShields > 0) {
            nShields--;
        }
    }

    public int getNShields() {
        return nShields;
    }
    
    public abstract void discardWeapon(Weapon w);
    
    public boolean hasNoEffect() {
        return nShields == 0;
    }
    
    public abstract DamageToUI getUIversion();

    public String toString() {
        String nS = "NSHIELDS: " + nShields + "\n";
        return nS;
    }
}

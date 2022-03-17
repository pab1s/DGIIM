/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author Angel Olmedo & Pablo Olivares
 */
public class SpecificDamage extends Damage {
    
    private static final int NOTINWEAPONS = -1;
    private ArrayList<WeaponType> weapons = new ArrayList<>();
    
    public SpecificDamage() {
        super();
        weapons = new ArrayList<>();
    }

    public SpecificDamage(ArrayList<WeaponType> wl, int s) {
        super(s);
        weapons = new ArrayList<>();
        
        for (WeaponType w : wl) {
            weapons.add(w);
        }
    }
    
    public SpecificDamage(SpecificDamage sd) {
        super(sd);
        weapons = new ArrayList<>();
        
        if (sd.weapons != null) {
            for (WeaponType w : sd.weapons) {
                weapons.add(w);
            }
        }
    }
    
    public ArrayList<WeaponType> getWeapons() {
        return weapons;
    }
    
    @Override
    public void discardWeapon(Weapon w) {
        weapons.remove(w.getType());
    }

    private int arrayContainsType(ArrayList<Weapon> w, WeaponType t) {
        int index = 0;
        for (Weapon weapon : w) {
            if (weapon.getType() == t) {
                return index;
            } else {
                index++;
            }
        }
        return NOTINWEAPONS;
    }

    @Override
    public Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s) {
        int index, retNShields = Math.min(nShields, s.size());
        ArrayList<WeaponType> typesCopy = new ArrayList<>();
        ArrayList<Weapon> weaponsCopy = new ArrayList<>();
        ArrayList<WeaponType> retWeapons = new ArrayList<>();
        Iterator<WeaponType> it;
            
        if ((weapons != null) && (!weapons.isEmpty())) {
            for (int i = 0; i < weapons.size(); i++) {
                typesCopy.add(weapons.get(i));
            }

            for (int i = 0; i < w.size(); i++) {
                weaponsCopy.add(w.get(i));
            }

            it = typesCopy.iterator();

            while (it.hasNext()) {
                WeaponType type = it.next();

                index = arrayContainsType(weaponsCopy, type);
                if (index != NOTINWEAPONS) {
                    weaponsCopy.remove(index);
                    retWeapons.add(type);
                }
                it.remove();
            }
        }
        return new SpecificDamage(retWeapons, retNShields);
    }

    @Override
    public boolean hasNoEffect() {
        return super.hasNoEffect() && weapons.isEmpty();
    }
    
    @Override
    public SpecificDamageToUI getUIversion() {
        return new SpecificDamageToUI(this);
    }

    @Override
    public String toString() {
        String finalString = super.toString();
        String wpns;

        wpns = "- WEAPONS: ";
        if (weapons == null || weapons.isEmpty()) {
            wpns += "None\n";
        } else {
            wpns += weapons.toString() + "\n";
        }

        finalString += wpns;
        
        return finalString;
    }
}

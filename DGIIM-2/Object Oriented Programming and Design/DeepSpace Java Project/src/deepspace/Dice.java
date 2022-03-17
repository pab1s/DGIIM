/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;
import java.util.Random;

/**
 *
 * @author Angel Olmedo & Pablo Olivares
 */
public class Dice {
    static float NHANGARSPROB;
    static float NSHIELDSPROB;
    static float NWEAPONSPROB;
    static float FIRSTSHOTPROB;
    static float EXTRAEFFICIENCYPROB;
    private Random generator;
    
    Dice(){
        NHANGARSPROB = 0.25f;
        NSHIELDSPROB = 0.25f;
        NWEAPONSPROB = 0.33f;
        FIRSTSHOTPROB = 0.5f;
        EXTRAEFFICIENCYPROB = 0.8f;
        generator = new Random();
    }
    
    int initWithNHangars(){
       float prob;
       prob = generator.nextFloat();
       
       if(prob < NHANGARSPROB)
           return 0;
       else
           return 1;
    }
    
    int initWithNWeapons(){
        float prob;
        prob = generator.nextFloat();
        
        if(prob < NHANGARSPROB)
            return 1;
        else if (prob < 2*NHANGARSPROB)
            return 2;
        else
            return 3;
    }
    
    int initWithNShields(){
        float prob;
        prob = generator.nextFloat();
        
        if(prob < NSHIELDSPROB)
            return 0;
        else
            return 1;
    }
    
    boolean extraEfficiency() {
        float prob = generator.nextFloat();
        
        if (prob < EXTRAEFFICIENCYPROB) {
            return true;
        }
        return false;
    }
    
    int whoStarts(int nPlayers){
        return generator.nextInt(nPlayers);
    }
    
    GameCharacter firstShot(){
        float prob;
        prob = generator.nextFloat();
        
        if(prob < FIRSTSHOTPROB)
            return GameCharacter.SPACESTATION;
        else
            return GameCharacter.ENEMYSTARSHIP;
    }
    
    boolean spaceStationMoves(float speed){
        float prob;
        prob = generator.nextFloat();
        
            return prob < speed;
    }
    
    public String toString(int numP, float sp){
        String finalString, iNH,iNW, iNS, wS, fS, ssM;
        
        iNH = "INITHANGARS: " + initWithNHangars() + "\n";
        iNW = "INITWEAPONS: " + initWithNWeapons() + "\n";
        iNS = "INITSHIELDS: " + initWithNShields() + "\n";
        wS = "WHOSTARTS: " + whoStarts(numP) + "\n";
        fS = "FIRSTSHOT: " + firstShot() + "\n";
        ssM = "STATIONMOVES: " + spaceStationMoves(sp) + "\n";
        
        finalString = iNH + iNW + iNS + wS + fS + ssM;
        
        return finalString;
    }
}
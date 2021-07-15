/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package View;
import java.util.ArrayList;
/**
 *
 * @author pablo
 */
import Controller.Controller;
import deepspace.GameUniverse;
import java.util.ArrayList;

/**
 * @brief Interfaz que implementan las vistas de usuario:
 *  -> Interfaz de Texto (User Interface : UI)
 *  -> Interfaz Gráfica (Graphic User Interface : GUI)
 */
public interface DeepSpaceView {
  public void updateView();
  public void showView();
  // Inputs
  public ArrayList<String> readNamePlayers();
  // Outputs
  public boolean confirmExitMessage();
  public void nextTurnNotAllowedMessage();
  public void lostCombatMessage();
  public void escapeMessage();
  public void wonCombatMessage();
  public void wonGameMessage();
  public void conversionMessage();
  public void noCombatMessage();
}
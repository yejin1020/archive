/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deu.cse.design_pattern.ch09.model02;

/**
 *
 * @author yejin
 */
public class WitressTest2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
      PancakeHouseMenu pancakeHouseMenu = new PancakeHouseMenu();
       DinerMenu dinerMenu = new DinerMenu();
        
      Waitress waitress = new Waitress(pancakeHouseMenu, dinerMenu);
        
        waitress.printMenu();
    }
    
}

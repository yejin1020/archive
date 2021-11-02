/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deu.cse.design_pattern.ch10.model02;

/**
 *
 * @author yejin
 */
public class TestDrive {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        	GumballMachine gumballMachine = new GumballMachine(5);

		System.out.println(gumballMachine);

		gumballMachine.insertQuarter();
		gumballMachine.turnCrank();

		System.out.println(gumballMachine);

		gumballMachine.insertQuarter();
		gumballMachine.turnCrank();
		gumballMachine.insertQuarter();
		gumballMachine.turnCrank();
		

		System.out.println(gumballMachine);
    }
    
}

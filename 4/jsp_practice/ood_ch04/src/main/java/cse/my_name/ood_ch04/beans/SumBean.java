/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch04.beans;

/**
 *
 * @author 920
 */
public class SumBean {
    
    private int n;
    private int result;

    public SumBean() {
        result = 0;
    }
    
    
    public void calculate(){
        result = n*(n+1)/2;
    }

    public int getN() {
        return n;
    }

    public void setN(int n) {
        this.n = n;
    }

    public int getResult() {
        return result;
    }
    
    
    
    
}

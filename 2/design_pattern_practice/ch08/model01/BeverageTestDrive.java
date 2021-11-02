package deu.cse.design_pattern.ch08.model01;


public class BeverageTestDrive {

    public static void main(String[] args) {
        
      CaffeineBeverage myTea = new Tea();
      myTea.prepareRecipe();
      
      System.out.println("====================");
      
      CaffeineBeverage myCoffee = new Coffee();
      myCoffee.prepareRecipe();
      
    }
    
}

package deu.cse.design_pattern.ch08.model02;

public class BeverageTestDrive {

    public static void main(String[] args) {
       
      // 티를 만든다
      CaffeineBeverageWithHook myTea = new TeaWithHook();
      myTea.prepareRecipe();
      
      System.out.println("====================");
      
      // 커피를 만든다.
      CaffeineBeverageWithHook myCoffee = new CoffeeWithHook();
      myCoffee.prepareRecipe();
    }
    
}

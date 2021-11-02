package deu.cse.design_pattern.ch04.model03;

public class ChicagostyleCheesePizza extends Pizza {
  public ChicagostyleCheesePizza() {
      name = " Chicago Style Deep Dish Cheese Pizza";
      dough = "Extra Thick Crust Dough";
      sauce = "Plum Tomato Sauce";
      
      toppings.add("Shredded Mozzarella Cheese");  
  }

  @Override
  public void cut() {
      System.out.println("Cutting the pizza into square slices");
  }

}

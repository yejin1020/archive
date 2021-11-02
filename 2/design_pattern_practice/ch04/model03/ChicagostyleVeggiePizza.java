package deu.cse.design_pattern.ch04.model03;

class ChicagostyleVeggiePizza extends Pizza {
  public ChicagostyleVeggiePizza() {
      name = "Chicago Deep Dish Veggie Pizza";
      dough = "Extra Thick Crust Dough";
      sauce = "Plum Tomato Sauce";
      
      toppings.add("Shredded Mozzarella Cheese");
      toppings.add("Black Olives");
      toppings.add("Spinach");
      toppings.add("Eggplant");
  }

  @Override
  public void cut() {
      System.out.println("Cutting the pizza into square slices");
  }

}

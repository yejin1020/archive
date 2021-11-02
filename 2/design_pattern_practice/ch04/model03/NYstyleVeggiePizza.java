package deu.cse.design_pattern.ch04.model03;

public class NYstyleVeggiePizza extends Pizza {
  public NYstyleVeggiePizza() {
      name = "NY Style VeggiePizza";
      dough = "Thin Crush Dough";
      sauce = "Marinara Sauce";
      
      toppings.add("Grated Reggiano Cheese");
      toppings.add("Garlic");
      toppings.add("Onion");
      toppings.add("Mushrooms");
      toppings.add("Red Pepper");
  }

}

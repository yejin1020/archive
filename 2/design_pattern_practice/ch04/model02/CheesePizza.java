package deu.cse.design_pattern.ch04.model02;
/**
 * 치즈 피자가 다른 피자와 다른 부분을 만든다.
 */
public class CheesePizza extends Pizza {
    
    public CheesePizza() {
        name = "Cheese Pizza";
        dough = "Regular Crust";
        sauce = "Marinare Pizza Sauce";
        toppings.add("Fresh Mozza");
        toppings.add("Parmesan");        
    }

}

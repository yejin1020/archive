package deu.cse.design_pattern.ch04.model02;


public class PizzaTestDrive {

    public static void main(String[] args) {
        SimplePizzaFactory factory = new SimplePizzaFactory();
        PizzaStore store = new PizzaStore(factory);
        
        Pizza pizza = store.orderPizza("cheese");
        System.out.println("Ethan ordered a" + pizza.name + "\n");
        
        pizza = store.orderPizza("veggie");
        System.out.println("Joel ordered a" + pizza.name + "\n");    
    }
    
}

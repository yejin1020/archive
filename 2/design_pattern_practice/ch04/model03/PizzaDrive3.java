package deu.cse.design_pattern.ch04.model03;

public class PizzaDrive3 {

    public static void main(String[] args) {
        
        PizzaStore nyStore = new NYPizzaStore();
        PizzaStore chicagoStore = new ChicagoPizzaStore();
        
        Pizza pizza = nyStore.orderPizza("veggie");
        System.out.println("ethan ordered a" + pizza.getName() + "\n");
        
        pizza = chicagoStore.orderPizza("veggie");
        System.out.println("ethan ordered a" + pizza.getName() + "\n");
   
    }
    
}
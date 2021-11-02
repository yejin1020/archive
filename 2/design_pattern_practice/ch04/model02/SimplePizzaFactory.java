package deu.cse.design_pattern.ch04.model02;
/**
 * 피자 생성을 맡긴다 
 * 피자의 종류는 여기에 작성한다. 
 */
public class SimplePizzaFactory {
    
  public Pizza createPizza(String type) {
      Pizza pizza = null;
      
      if( type.equals("cheese")){
          pizza = new CheesePizza();
      }else if( type.equals("pepperoni")){
          pizza = new PepperoniPizza();
      }else if( type.equals("clam")){
          pizza = new ClamPizza();
      }else if( type.equals("veggie")){
          pizza = new VeggiePizza();
      }
      return pizza;
  }

}

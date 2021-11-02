package deu.cse.design_pattern.ch04.model03;
/**
 * 뉴욕풍 피자를 생성
 */
public class NYPizzaStore extends PizzaStore {

  public Pizza createPizza(String type) {

      if( type.equals ("cheese")){
          return new NYstyleCheesePizza();
      }else if ( type.equals("veggie")){
          return new NYstyleVeggiePizza();
      }else{
          return null;
      }
    }
  
}

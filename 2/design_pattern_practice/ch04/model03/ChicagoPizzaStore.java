package deu.cse.design_pattern.ch04.model03;
/**
 * 시카고 풍 피자를 생성
 */
public class ChicagoPizzaStore extends PizzaStore {
  public Pizza createPizza(String type) {
       if( type.equals ("cheese")){
          return new ChicagostyleCheesePizza();
      }else if ( type.equals("veggie"))
      { return new ChicagostyleVeggiePizza();
      }else{
          return null;
      }
  }
}

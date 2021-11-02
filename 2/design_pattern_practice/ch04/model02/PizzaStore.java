package deu.cse.design_pattern.ch04.model02;
 /**
  * SimplePizzaFactory를 넣음으로써
  * Pizza의 종류가 생성된 것을 받는다
  * Pizza클래스와 연결이 조금 느슨해진다.
  */
class PizzaStore {

    private SimplePizzaFactory factory; 
    
    public PizzaStore(SimplePizzaFactory factory) {
        this.factory = factory;
    }
/**
 *  createPizza 하는 부분이 다른 클래스로 분리되어
 * orderPizza 메소드를 부를때 자신이 원하는 피자 종류만 넘겨주면
 * 종류 별로 다른 피자를 생성할 수 있다.
 */
    public Pizza orderPizza(String type) {
        Pizza pizza;
        
        pizza = factory.createPizza(type);    // factory method 사용
        pizza.prepare();
        pizza.bake();
        pizza.box();
        
        return pizza;
    }


}

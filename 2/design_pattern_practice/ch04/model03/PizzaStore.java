package deu.cse.design_pattern.ch04.model03;
/**
 * createPizza 를 사용하여 원하는 스타일의 피자를 생성해서 주문에 대응
 */
public abstract class PizzaStore {
    // 팩토리 메소드이나 추상 오퍼레이션. 서브 클래스에서 객체 생성을 구체화한다.
  protected abstract Pizza createPizza(String type);
   // 팩토리 메소드를 사용하여 피자 객체를 만들고 최종으로 박스에 담을 때 까지 과정을 기술
  public Pizza orderPizza(String type) {
        
        Pizza pizza = createPizza(type);
      
        System.out.println("---Making a" + pizza.getName()+ "---");
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        
        return pizza;
  }

}

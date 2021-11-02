package deu.cse.design_pattern.ch03.model02;
/**
 * Component를 생성하는 클래스
 * Beverage를 상속 받은 ConcreteComponent ( Espresso,Houseblend)는
 * 값이 변경되지 않는다.
 */
abstract class Beverage {
  protected String description = "Unknown Beverage";
  
    // 원래 음료의 description은 변경되지 않음
  public String getDescription() {
      return description;
  }

  public abstract double cost() ;

}

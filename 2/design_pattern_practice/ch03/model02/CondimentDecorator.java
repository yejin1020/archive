package deu.cse.design_pattern.ch03.model02;
/**
 * ConcreteDecorator(Milk.Mocha)의 기본 기능을 구현
 * beverage와 연관관계를 가진다.
 */
abstract class CondimentDecorator extends Beverage {

    protected Beverage beverage;
    
    // 첨가된 가격을 적는다.
    @Override
    public abstract String getDescription() ;

}

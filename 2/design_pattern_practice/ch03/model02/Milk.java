package deu.cse.design_pattern.ch03.model02;
/**
 * 기본 Component ( Espresso,Houseblend)에 기능을 추가한다
 * CondimentDecorator의 하위클래스
 */
class Milk extends CondimentDecorator {
    public Milk(Beverage beverage) {
        this.beverage = beverage;
    }

    public double cost() {
        return .10 + beverage.cost();
    }

    public String getDescription() {
        return beverage.getDescription() + ",Milk";
    }
}

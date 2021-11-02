package deu.cse.design_pattern.ch03.model02;
/**
 * HouseBlend의 기본 기능이있다.
 * 
 */
class HouseBlend extends Beverage {
    
    public HouseBlend() {
        description = " HouseBlend Coffee";
    }
    public double cost() {
        return .89;
    }
}

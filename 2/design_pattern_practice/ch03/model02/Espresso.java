package deu.cse.design_pattern.ch03.model02;
//Espresso의 기본 기능이 있다.
class Espresso extends Beverage {
    public Espresso() {
        description = "Espresso";
    }

    public double cost() {
        return 1.99;
    }
}

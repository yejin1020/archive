package deu.cse.design_pattern.ch08.model01;

abstract class CaffeineBeverage {
  public final void prepareRecipe() {
      boilWater();
      brew();
      pourInCup();
      addCondiments();
  }

  protected abstract void brew() ;

  protected abstract void addCondiments() ;

  public void boilWater() {
      System.out.println("물 끓이는 중");
  }

  public void pourInCup() {
      System.out.println("컵에 따르는 중");
  }

}

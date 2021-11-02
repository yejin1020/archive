package deu.cse.design_pattern.ch08.model01;

class Tea extends CaffeineBeverage {
  protected void brew() {
      System.out.println("차를 우려내는 중");
  }

  protected void addCondiments() {
      System.out.println("레몬을 추가하는 중");
  }

}

package deu.cse.design_pattern.ch08.model01;

class Coffee extends CaffeineBeverage {
  protected void brew() {
      System.out.println("필터를 통해서 커피를 우려내는 중");
  }

  protected void addCondiments() {
      System.out.println("설탕과 우유를 추가하는 중");
  }

}

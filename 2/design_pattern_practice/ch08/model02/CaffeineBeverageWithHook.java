package deu.cse.design_pattern.ch08.model02;

abstract class CaffeineBeverageWithHook {
    // 템플릿 메서드 패턴에서 사용되는 알고리즘,
    // 알고리즘 내에서 사용되는 메서드가 있다.
 public final void prepareRecipe() {
      boilWater();
      brew();
      pourInCup();
      
    //Hook, Hook가 있으면 서브클래스에서 
    //템플릿 내의 일부를 오버라이드 할 수 있다.
    // addCondiments는 서브클래스에서 사용될 수 도 있고 안될 수도 있다.
      if( customerWantsCondiments() )
            addCondiments();
  }

 // 구상 클래스에서 무조건 구현해줘야한다.
 // 추상클래스이기 때문
  protected abstract void brew() ;

  protected abstract void addCondiments() ;

  public void boilWater() {
      System.out.println("물 끓이는 중");
  }

  public void pourInCup() {
      System.out.println("컵에 따르는 중");
  }
  
  // 기본적으로 실행되도록 초기설정 해둔다  
  protected boolean customerWantsCondiments() {
      return true;
  }

}

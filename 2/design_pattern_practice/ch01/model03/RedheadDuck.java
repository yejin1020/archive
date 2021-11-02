
package deu.cse.design_pattern.ch01.model03;

class RedheadDuck extends Duck {
    
    public RedheadDuck(){
       
       quackBehavior = new Quack();
       flyBehavior = new FlyWithWings();
       
   } 
  public void display() {
      System.out.println("저는 redheadduck 입니다.");
  }

}

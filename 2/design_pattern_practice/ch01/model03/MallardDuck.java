
package deu.cse.design_pattern.ch01.model03;

class MallardDuck extends Duck {
    
   public MallardDuck(){
       
       quackBehavior = new Quack();
       flyBehavior = new FlyWithWings();
       
   } 
  public void display() {
      System.out.println("저는 mallardduck 입니다.");
  }

}

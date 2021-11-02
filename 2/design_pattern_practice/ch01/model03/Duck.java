package deu.cse.design_pattern.ch01.model03;

abstract class Duck {
   
 protected FlyBehavior flyBehavior; // interface
 protected QuackBehavior quackBehavior; // interface

  public void swim() {
      System.out.println("모든 오리는 물에 뜹니다.");
  }

  public abstract void display() ; 

  public void performFly() {
      flyBehavior.fly();;
  }

  public void performQuack() {
      quackBehavior.quack();
  }

  public void setFlyBehavior(FlyBehavior fb ) {
      flyBehavior = fb;
  }

  public void setQuackBehavior( QuackBehavior qb) {
      quackBehavior = qb;
  }


}

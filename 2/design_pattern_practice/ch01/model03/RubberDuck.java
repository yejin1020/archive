
package deu.cse.design_pattern.ch01.model03;

class RubberDuck extends Duck {
    
    public RubberDuck(){

     quackBehavior = new Squeak();
     flyBehavior = new FlyNoWay();

    }   
    public void display() {
        System.out.println("저는 rubberduck 입니다.");
    }

}


package deu.cse.design_pattern.ch01.model03;

class DecoyDuck extends Duck {
    
    public DecoyDuck(){

    quackBehavior = new MuteQuack();
    flyBehavior = new FlyNoWay();

    }   
    public void display() {
       System.out.println("저는 decoyduck 입니다.");
    }

}

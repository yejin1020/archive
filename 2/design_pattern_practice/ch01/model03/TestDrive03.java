package deu.cse.design_pattern.ch01.model03;

public class TestDrive03 {

    public static void main(String[] args) {
       Duck mallardduck = new MallardDuck();
       Duck redheadduck = new RedheadDuck();
       Duck rubberduck = new RubberDuck();
       Duck decoyduck = new DecoyDuck();
       
       mallardduck.display();
       mallardduck.performFly();
       mallardduck.performQuack();
       
       redheadduck.display();
       redheadduck.performFly();
       redheadduck.performQuack();
       
       rubberduck.display();
       rubberduck.performFly();
       rubberduck.performQuack();
       
       decoyduck.display();
       decoyduck.performFly();
       decoyduck.performQuack();
       
       decoyduck.setFlyBehavior( new FlyRocketPowered() );
       decoyduck.performFly();
    }
    
}

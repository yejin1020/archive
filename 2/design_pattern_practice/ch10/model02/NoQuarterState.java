package deu.cse.design_pattern.ch10.model02;

public class NoQuarterState implements State {
    
  GumballMachine gumballMachine;

    public NoQuarterState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    public void insertQuarter() {
            System.out.println("You inserted a quarter");
            // 상태 전환 이루어짐
            gumballMachine.setState(gumballMachine.getHasQuarterState());
    }

    public void ejectQuarter() {
            System.out.println("You haven't inserted a quarter");
    }

    public void turnCrank() {
            System.out.println("You turned, but there's no quarter");
     }

    public void dispense() {
            System.out.println("You need to pay first");
    } 

    public String toString() {
        return "waiting for Quarter";
    }

}

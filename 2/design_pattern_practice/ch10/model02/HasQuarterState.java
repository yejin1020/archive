package deu.cse.design_pattern.ch10.model02;

// 동전이 들어가 있을 때 상태
public class HasQuarterState implements State {
    
      GumballMachine gumballMachine;
      java.util.Random randomWinner = new java.util.Random(System.currentTimeMillis());
      
    public HasQuarterState(GumballMachine gumballMachine) {
            this.gumballMachine = gumballMachine;
    }

    public void insertQuarter() {
            System.out.println("You can't insert another quarter");
    }

    public void ejectQuarter() {
            System.out.println("Quarter returned");
            // 검볼머신의 상태를 가지고와서 지정한다.
            gumballMachine.setState(gumballMachine.getNoQuarterState());
    }

    public void turnCrank() {
            System.out.println("You turned...");
            int winner = randomWinner.nextInt(10);
            // 껌이 2개 이상일 때 실행되게한다.
            if( winner == 0 && gumballMachine.getCount() > 1 ){
                gumballMachine.setState(gumballMachine.getWinnerState());
            }else {
                gumballMachine.setState(gumballMachine.getSoldState());
            }
            
    }

    public void dispense() {
    System.out.println("No gumball dispensed");
    }

    public String toString() {
            return "waiting for turn of crank";
    }
}



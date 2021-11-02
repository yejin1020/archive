package deu.cse.design_pattern.ch10.model02;

public class WinnerState implements State {
    
     GumballMachine gumballMachine;
 
    public WinnerState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }
 
	public void insertQuarter() {
		System.out.println("Please wait, we're already giving you a Gumball");
	}
 
	public void ejectQuarter() {
		System.out.println("Please wait, we're already giving you a Gumball");
	}
        
        public void turnCrank() {
		System.out.println("Turning again doesn't get you another gumball!");
	}
 
	public void dispense() {
            System.out.println("YOU'RE A WINNER! You got two gumballs for your quarter");
		gumballMachine.releaseBall();
		if (gumballMachine.getCount() == 0) {
                    // 이부분은 실행되지 않는다.
			gumballMachine.setState(gumballMachine.getSoldOutState());
		} else {
			gumballMachine.releaseBall();
			if (gumballMachine.getCount() > 0) {
				gumballMachine.setState(gumballMachine.getNoQuarterState());
			} else {
                                   System.out.println("Oops, out of gumballs!");
				gumballMachine.setState(gumballMachine.getSoldOutState());
			}
		}
	}
 
	public void refill() { }
	
	public String toString() {
		return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
	}
}

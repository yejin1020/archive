package deu.cse.design_pattern.ch10.model02;

public class GumballMachine {
    
    State soldOutState;
    State noQuarterState;
    State hasQuarterState;
    State soldState;
    State winnerState;
    State state;
    int count = 0;

    public GumballMachine(int numberGumballs) {
       
            // 기계의 상태를 정한다.
            soldOutState = new SoldOutState(this);
            noQuarterState = new NoQuarterState(this);
            hasQuarterState = new HasQuarterState(this);
            soldState = new SoldState(this);
            winnerState = new WinnerState(this);
            
            // 껌의 개수와, 껌이 채워졌을 댸 기계 상태를 정한다. 
            this.count = numberGumballs;
            if (numberGumballs > 0) {
                    state = noQuarterState;
            } 
    }

    // 동전이 들어왔을 때, 그 때 기계의 상태에 맞춰 동작한다.
    public void insertQuarter() {
            state.insertQuarter();
    }
    
    // 반환 요정이 들어왔을 때.
    public void ejectQuarter() {
            state.ejectQuarter();
    }

    // 손잡이를 돌렸을 때
    public void turnCrank() {
            state.turnCrank();
            state.dispense();
    }

    // 껌을 내놓을 때
    void releaseBall() {
            System.out.println("A gumball comes rolling out the slot...");
            if (count != 0) {
                    count = count - 1;
            }
    }

    int getCount() {
            return count;
    }

    void setState(State state) {
            this.state = state;
    }
    
    public State getState() {
        return state;
    }

    public State getSoldOutState() {
     return soldOutState;
    }

    public State getNoQuarterState() {
     return noQuarterState;
    }

    public State getHasQuarterState() {
         return hasQuarterState;
    }

    public State getSoldState() {
        return soldState;
    }
    
    public State getWinnerState() {
        return winnerState;
}
    
    // 기께의 현재 상태 출력
    public String toString() {
            StringBuffer result = new StringBuffer();
            result.append("\nMighty Gumball, Inc.");
            result.append("\nJava-enabled Standing Gumball Model #2004");
            result.append("\nInventory: " + count + " gumball");
            if (count != 1) {
                    result.append("s");
            }
            result.append("\n");
            result.append("Machine is " + state + "\n");
            return result.toString();
    }

}

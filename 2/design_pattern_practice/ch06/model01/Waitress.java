package deu.cse.design_pattern.ch06.model01;
//인보커인 웨이트리스는 command인터페이스에 의존한다.
// 리시버나 concrete command에 대해서 몰라도 된다.
public class Waitress {

  private Command command;
    
  public void takeOrder() {
      System.out.println("웨이트리스가 주문을 받습니다");
      command.orderUp();
      // command 의 oderup을 호출하여 리시버인 세프가 일을 한다.
  }

  // command 값을 받아서 실행할 수 있게한다.
  public void setCommand(Command command) {
      this.command = command;
  }
}

package deu.cse.design_pattern.ch06.model02;
//인보커
public class SimpleRemoteControl {
  private Command command;

  public  SimpleRemoteControl() {
  }

  //사용할 커맨드가 어떤 것인지 알기위해 커맨드를 넘겨받아야한다.
  public void setCommand(Command command) {
      this.command = command;
      //커맨드 interface가 제일 상위이기 때문에 어떤 커맨드가 와도 상관없다.
  }

  public void buttonWasPressed() {
      command.execute();
      //커맨드의 execute를 실행하여 일하게한다.
  }

}

package deu.cse.design_pattern.ch06.model03;

public class CeilingFanOffCommand implements Command {
    //어떤 ceilingfan인지 알고 있어야하므로
    //인스턴스 변수로 연관함
    private CeilingFan fan;

  // 생성자에서 어떤 fan인지 초기화.
  public CeilingFanOffCommand(CeilingFan fan) {
      this.fan = fan;
  }

  //연결된 ceilingfan의 off을 실행한다.
  public void execute() {
      fan.off();
  }
  
  public void undo(){
      fan.on();
  }

}

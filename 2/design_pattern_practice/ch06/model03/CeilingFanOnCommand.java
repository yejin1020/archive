package deu.cse.design_pattern.ch06.model03;
//특정행동과 receiver를 연결한다.

public class CeilingFanOnCommand implements Command {
     //어떤 ceilingfan인지 알고 있어야하므로
    //인스턴스 변수로 연관함
    private CeilingFan fan;
 
    //특정 ceilingfan을 전달받아 연결.
  public CeilingFanOnCommand(CeilingFan fan) {
      this.fan = fan;
  }

  //연결된 ceilingfan의 on을 실행한다.
  public void execute() {
      fan.on();
  }
  
  public void undo(){
      fan.off();
  }

}

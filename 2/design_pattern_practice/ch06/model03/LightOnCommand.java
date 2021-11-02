package deu.cse.design_pattern.ch06.model03;

// 리시버인 라이트와 연결
public class LightOnCommand implements Command {
    // 어떤 위치의 리시버인지 받기 위해서 정의함
  private Light light;

  //receiver인 light를 받아서 연결시킨다.
  public LightOnCommand(Light light) {
      this.light = light;
  }

  //light의 on을 수행한다.
  public void execute() {
      light.on();
  }
  
  public void undo(){
      light.off();
  }

}

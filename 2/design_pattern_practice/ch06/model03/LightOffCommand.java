package deu.cse.design_pattern.ch06.model03;

//리시버 ( light )를 전달 받아 off를 실행 시킨다.
class LightOffCommand implements Command {
  private Light light;

  //receiver인 light를 받아서 연결시킨다.
  public LightOffCommand(Light light) {
      this.light = light;
  }
 
//light의 off을 수행한다.
  public void execute() {
      light.off();
  }
public void undo(){
      light.on();
  }
}

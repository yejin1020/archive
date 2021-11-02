package deu.cse.design_pattern.ch06.model02;

class LightOnCommand implements Command {
    
    static boolean toggle = true;
    private Light light;
    //리시버인 light가 어떤 것인지 알고 있어야하므로 
    // 연관으로 만들었다.
    //인스턴스 변수로 연관함.??
  public LightOnCommand(Light light) {
      this.light = light;
      //light 객체를 매개변수로 받아서 연결시켜주었음.
  }

  public void execute() {
   //연결된 light의 on 매서드를 호출하였다.        
      if( toggle == true )
      { 
          light.on();
          toggle = false;
      }else {
          light.off();
          toggle = true;
       }
  }

}

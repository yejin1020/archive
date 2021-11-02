package deu.cse.design_pattern.ch06.model03;
// receiver. 명령을 처리하기위한 일을 알고있다.
// ceilingfan이 하는 일을 처리한다.
public class CeilingFan {
    
  private String location;

  public CeilingFan(String location) {
      this.location = location;
  }

  public void on() {
      System.out.println(location + "천장 선풍기가 켜졌습니다.");
  }

  public void off() {
     System.out.println(location + "천장 선풍기가 꺼졌습니다.");
  }
 
}

package deu.cse.design_pattern.ch06.model03;
// receiver 명령을 처리하기위한 일을 알고있다.
// light가 하는 일을 처리한다.
public class Light {
    // 어디 위치인지 받아온다.
  private String location;

  public Light(String location) {
      this.location = location;
  }

  public void on() {
       System.out.println(location + "조명이 켜졌습니다.");
  }

  public void off() {
       System.out.println(location + "조명이 꺼졌습니다.");
  }

}

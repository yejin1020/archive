package deu.cse.design_pattern.ch06.model02;

public class TestDriver {

    public static void main(String[] args) {
        
        //인보커
        SimpleRemoteControl remote = new SimpleRemoteControl();
        
        // 라이트 리시버 생성
        Light light = new Light();
        //구체화된 커맨드에 라이트 리시버 전달
        LightOnCommand lightOn = new LightOnCommand(light);
        // 리모컨( 인보커)에 커맨드 연결시켜준다.
        remote.setCommand(lightOn);
        
        // 리모컨은 그냥 누르기만 한다.
        // 버튼을 누르면 라이트의 execute가 실행된어 불이 켜진다.
        
        remote.buttonWasPressed();
        remote.buttonWasPressed();
        remote.buttonWasPressed();
        remote.buttonWasPressed();
                      
        //command가 어떤 것인지 연결하고         
        GarageDoor garageDoor = new GarageDoor();
        GarageDoorOpenCommand garageOpen =
                new GarageDoorOpenCommand(garageDoor);
        
        //invoker에서는 그냥 command 넘겨받아서 버튼만 누른다.
        remote.setCommand(garageOpen);
        remote.buttonWasPressed();
       
        
    }
    
}

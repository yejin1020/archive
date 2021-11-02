package deu.cse.design_pattern.ch06.model03;

public class RemoteLoader {

    public static void main(String[] args) {
       RemoteControl remote = new RemoteControl();
       
       // 거실 전용 설정 : 슬롯 0
       // 거실에서 동작하는 조명 객체 생성
       Light livingRoomLight = new Light ("거실");
       //거실 조명을 조명을 켜는 command 객체와 연결한다.
       LightOnCommand livingRoomLightOn = new LightOnCommand( livingRoomLight);
       //거실 조명을 조명을 끄는 command 객체와 연결한다.
       LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);
       //invoker remote를 사용하여 위에서 생성된 조명command 객체들을 저장한다.
       remote.setCommand(0,livingRoomLightOn,livingRoomLightOff);
       
       //부엌 전등 설정: 슬롯 1
       // 부엌에서 동작하는 조명 객체 생성
       Light kitchenLight = new Light ("부엌");
       //부엌 조명을 조명을 켜는 command 객체와 연결한다.
       LightOnCommand kitchenLightOn = new LightOnCommand( kitchenLight);
        //부엌 조명을 조명을 끄는 command 객체와 연결한다.
       LightOffCommand kitchenLightOff = new LightOffCommand(kitchenLight);
       //invoker remote를 사용하여 위에서 생성된 조명command 객체들을 저장한다.
       remote.setCommand(1,kitchenLightOn,kitchenLightOff);
       
       //거실 선풍기 설정 : 슬롯 2
       // 거실에서 동작하는 선풍기 객체 생성
       CeilingFan fan = new CeilingFan("거실");
       //선풍기 객체를 선풍기를 켜는 command 객체와 연결한다.
       CeilingFanOnCommand fanOn = new CeilingFanOnCommand(fan);
       //선풍기 객체를 선풍기를 끄는 command 객체와 연결한다.
       CeilingFanOffCommand fanOff = new CeilingFanOffCommand(fan);
       //invoker remote를 사용하여 위에서 생성된 선풍기command 객체들을 저장한다.
       remote.setCommand(2,fanOn,fanOff);
       
       
        Command[] temp1 = {livingRoomLightOn,kitchenLightOn};
       Command[] temp2 = {livingRoomLightOff,kitchenLightOff};
       MacroCommand allLightsOn = new MacroCommand(temp1);
       MacroCommand allLightsOff = new MacroCommand(temp2);
       remote.setCommand(5,allLightsOn,allLightsOff);
       
      //toString을 사용하여 슬롯의 내용을 출력한다.
       System.out.println(remote);
       
       //각 슬롯의 리모콘 버튼을 눌러본다.
       for( int i = 0 ; i < RemoteControl.MAX_COMMANDS ; i++){
           System.out.println("[슬롯" + i + "]");
           remote.onButtonWasPushed(i);
           remote.offButtonWasPushed(i);       
           remote.undoButtonWasPressed();
       }

    }
    
}

package deu.cse.design_pattern.ch06.model03;

import java.util.ArrayList;
import java.util.List;

//invoker
// 명령을 전달받아 커맨드 객체에게 수행해달라고 요청한다.

public class RemoteControl {
    
   //리모콘의 on,off 명령을 처리할 배열을 생성한다.
  public static final int MAX_COMMANDS = 7;
  private List<Command> offCommands = new ArrayList<>();
  private  List<Command> onCommands = new ArrayList<>();
  private Command undoCommand;
 
  public RemoteControl() {
      //리모콘 버튼을 NoCommand 객체로 모두 초기화
      // 0-6번의 리스트가 만들어지니다.
      Command noCommand = new NoCommand();
      for( int i  = 0; i< MAX_COMMANDS ; i++){
          onCommands.add(i,noCommand);
          offCommands.add(i,noCommand);
      }
      
      undoCommand = noCommand;
  }
  
  // 수행하라고 알려줄 곳이 어디인지 알아야한다.
  // 슬롯 번호와 그 슬롯에 저장할 on및 off 명령을 인자로 전달 받는다.
  // 각 커맨드 객체를 나중에 사용할 수 있도록 배열에 저장한다.
  public void setCommand(int slot, Command onCommand, Command offCommand) {
      onCommands.set(slot, onCommand);
      offCommands.set(slot,offCommand);
  }
  
  // 전달받은 슬롯 번호에 해당하는 객체를 on하라고 알려준다.
  public void onButtonWasPushed(int slot) {
      onCommands.get(slot).execute();
      undoCommand = onCommands.get(slot);
  }

   // 전달받은 슬롯 번호에 해당하는 객체를 on하라고 알려준다.
  public void offButtonWasPushed(int slot) {
      offCommands.get(slot).execute();
      undoCommand = offCommands.get(slot);
  }
  
  // 모든 기능 undo 실행
  public void undoButtonWasPressed(){
      undoCommand.undo();
  }

  // 슬롯 정보 출력
  public String toString() {
      StringBuilder buf = new StringBuilder();
      
      //각 슬롯의 클래스 타입과 클래스 이름을 출력한다.
      buf.append("\n------ Remote Control -------\n");
      for( int i = 0 ; i < onCommands.size() ; i++){
          buf.append("[slot").append(i).append("]");
          buf.append( onCommands.get(i).getClass().getName() ).append(" ");
          buf.append( offCommands.get(i).getClass().getName() ).append("\n");
      }
      return buf.toString();
  }

}

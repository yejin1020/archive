package deu.cse.design_pattern.ch06.model03;
// 슬롯 5의 전체 전등모드와 슬롯 6의 파티 모드를 구현하기위한 매크로 커맨드 
public class MacroCommand implements Command{
    private Command[] commands;
    
    // 커맨드 배열을 받는다.
    public MacroCommand( Command[] commands){
        this.commands = commands;
    }
    
    // 모든 커맨드에 대해서 실행
    public void execute() {
        for( int i = 0 ; i < commands.length ; i ++){
            commands[i].execute();
        }
    }
    
    // 모든 커맨드에 대해서 undo 실행
    public void undo(){
        for( int i = 0 ; i < commands.length ; i++){
           commands[i].undo();
        }
    }
    
    
}

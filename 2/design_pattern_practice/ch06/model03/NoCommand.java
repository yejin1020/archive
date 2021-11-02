package deu.cse.design_pattern.ch06.model03;

public class NoCommand implements Command {
  public void execute() {
     System.out.println("아무 것도 실행되지 않습니다.");
  }
  public void undo(){
      System.out.println("아무 것도 실행되지 않습니다.");
  }
}

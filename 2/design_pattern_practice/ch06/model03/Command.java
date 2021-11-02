package deu.cse.design_pattern.ch06.model03;
// 커맨트 인터페이스
// concrete command 객체들이 구체화한다.
public interface Command {
  void execute() ;
  void undo();
}

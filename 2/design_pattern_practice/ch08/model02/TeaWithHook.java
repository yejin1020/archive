package deu.cse.design_pattern.ch08.model02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// CaffeineBeverageWithHook와 다른 부분을 구현한다.
class TeaWithHook extends CaffeineBeverageWithHook {
   // 다른 부분 1
  protected void brew() {
      System.out.println("차를 우려내는 중");
  }
  
  // 다른 부분2
  protected void addCondiments() {
      System.out.println("레몬을 추가하는 중");
  }
  
  //addCondiments를 사용할지 판단
  protected boolean customerWantsCondiments() {
     // 넣을지 말지 입력을 받는다
      String answer  = getUserInput();
      
      // 소문자로 만들고 y로 시작하는지 확인한다.
      if( answer.toLowerCase().startsWith("y")){
          return true;
      }else{
          return false;
      }
  }
  
  // 사용자 입력 받는다.
  private String getUserInput(){
      
      String answer  = null;
      
      System.out.print("차에 레몬을 넣에드릴까요?");
      
      BufferedReader in = new BufferedReader( new InputStreamReader(System.in));
      
      try{
          answer = in.readLine();
      }catch ( IOException ioe){
          System.err.println(ioe);
      }
      if( answer == null){
          return "no";
      }
      return answer;
  }

}

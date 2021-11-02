package deu.cse.design_pattern.ch08.model02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//  템플릿에서 구현되지 않은 부분을 클래스에 맞게 정의된다.
class CoffeeWithHook extends CaffeineBeverageWithHook {
    
   // 템플릿에서 다른 부분1
  protected void brew() {
      System.out.println("필터를 통해서 커피를 우려내는 중");
  }
  
 // 템플릿에서 다른 부분2
  protected void addCondiments() {
      System.out.println("설탕과 우유를 추가하는 중");
  }

  //템플릿의 일부를 사용할지 판단
    protected boolean customerWantsCondiments() {
     // 넣을지 말지 입력을 받는다
      String answer  = getUserInput();
      
      // 사용자 입력을 소문자로 만들고 y로 시작하는지 확인한다.
      if( answer.toLowerCase().startsWith("y")){
          return true;
      }else{
          return false;
      }
  }
    
    // 사용자의 입력을 받는다.
    private String getUserInput(){
      
      String answer  = null;
      
      System.out.print("커피에 설탕과 우유를 넣어드릴까요? ( y/n)");
      
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

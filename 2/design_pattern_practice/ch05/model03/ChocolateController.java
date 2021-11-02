package deu.cse.design_pattern.ch05.model03;

public class ChocolateController {

    public static void main(String[] args) {
        
       new Thread( () -> {
           ChocolateBoiler boiler = ChocolateBoiler.getInstance();
           System.out.println("객체 정보 : " + boiler);
           boiler.fill();
           boiler.boil();
           boiler.drain();
       }).start();

       // 스레드 동작시간에 차이를 준다.
       // 객체 생성하는 부분을 실행하는 데 간격이 생긴다.
      try{
           Thread.sleep(500);
       }catch ( InterruptedException ex){
           System.out.println(ex);
       }
       
       new Thread( () -> {
           ChocolateBoiler boiler = ChocolateBoiler.getInstance();
           System.out.println("객체 정보 : " + boiler);
           boiler.fill();
           boiler.boil();
           boiler.drain();
       }).start();
       
    }
    
}

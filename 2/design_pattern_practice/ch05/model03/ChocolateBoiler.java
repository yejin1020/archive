package deu.cse.design_pattern.ch05.model03;

public class ChocolateBoiler {
    
    private boolean empty;
    private boolean boiled;
    private static ChocolateBoiler uniqueinstance;
    
    private ChocolateBoiler() {
        empty = true;
        boiled = false;
        System.out.println("ChocolateBoiler 생성자가 실행됩니다.");
    }
    // 싱글턴 패턴을 적용하여 유일한 객체를 반환하게한다.
   public static synchronized ChocolateBoiler getInstance(){
       
       if(uniqueinstance == null){
          
           // 객체를 1초 뒤에 생성하도록한다.
           try {
               System.out.println("\n 1초간 지연됩니다.");
               Thread.sleep(1000);
           }catch ( InterruptedException ex){
               System.err.println(ex);
           }
          
           // 유일한 객체 생성
           System.out.println("\n 1. 초콜릿 보일러의 유일한 객체를 생성\n");
           uniqueinstance = new ChocolateBoiler();
       }
       
       // 이전에 생성된 객체를 반환한다.
       System.out.println("\n 2. 초콜릿 보일러의 객체를 반환\n");
          return uniqueinstance;
     
   }
   
   public void fill(){
       if( isEmpty() ){
           empty= false;
           boiled = false;
           System.out.println("보일러가 비어있으므로 초콜렛과 우유를 채웁니다.\n");
       }
   }
   
   public void drain(){
       
       if( !isEmpty() && isBoiled()){
           empty = true;
           System.out.println("차있으며 끓고 있으므로 이제 버립니다.\n");
       }
   }
   
   public void boil() {
       if( !isEmpty() && isBoiled()){
           boiled = true;
           System.out.println("보일러에 초콜렛과 우유가 있으므로 끓입니다.\n");
       }
   }
   
   public boolean isEmpty(){
       return empty;
   }
   
   public boolean isBoiled(){
       return boiled;
   }
}

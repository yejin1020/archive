package deu.cse.design_pattern.ch04.model03;

import java.util.ArrayList;
import java.util.List;
// 피자 기본을 생성하는 추상 클래스
public abstract class Pizza {
    
  protected List<String> toppings = new ArrayList<>();
  protected String name;
  protected String dough;
  protected String sauce;

  public void prepare() {
       System.out.println("prepareing" + name );
       toppings.forEach( topping -> {
           System.out.println(" " + topping);
       });
  }

  public void bake() {
      System.out.println("baking" + name );
  }

  public void cut() {
      System.out.println("cutting" + name );
  }

  public void box() {
      System.out.println("boxing" + name );
  }

    public String getName() {
        return name;
    }

  @Override
  public String toString(){
        StringBuilder display = new StringBuilder();
        display.append("---" ).append( name ).append("---\n");
        display.append(dough).append("\n");
        display.append(sauce).append("\n");
        // toopings에 있는 아이템을 topping으로 받은 다음에
        // 각 값에 대하여 display.append(topping).append("\n");수행한다.
        toppings.forEach( topping -> {
            display.append(topping).append("\n");
        });
        return display.toString();
  }
         
}

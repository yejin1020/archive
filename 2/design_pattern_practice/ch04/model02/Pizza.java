package deu.cse.design_pattern.ch04.model02;

import java.util.ArrayList;
import java.util.List;
// 피자 생성에 기본적으로 필요한 클래스
public  abstract class Pizza {
    
    protected List<String> toppings = new ArrayList<>();
    protected String name;
    protected String dough;
    protected String sauce;

    public void prepare() {
        System.out.println("prepareing" + name );
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
    
    @Override
    public String toString() {
        StringBuilder display = new StringBuilder();
        
        display.append("---" + name + "---\n");
        display.append(dough + "\n");
        display.append(sauce + "\n");
        for( int i = 0 ; i< toppings.size() ; i++){
            display.append(toppings.get(i) + "\n");
        }
        return display.toString();
    }


}

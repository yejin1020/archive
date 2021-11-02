package deu.cse.design_pattern.ch09.model02;

import deu.cse.desing_patttern.ch09.model01.MenuItem;
import java.util.ArrayList;

class PancakeHouseMenu {

 // 생성자 안에서만 메뉴아이템 설정. 초기값 설정 제외 수정 불가
    private final ArrayList<MenuItem> menuItems;

    public PancakeHouseMenu() {
        menuItems = new ArrayList<>();
        
        addItem("K&B's Pancake Breakfast","Pancakes with scrambled eggs and toast",true,2.99);
        addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
        addItem("BlueBerry Pancakes","Pancakes made with fresh blueberries",true,3.49);
        addItem("Waffles","Waffles with your choice of blueberries or strawberries",true,3.59);
        
        
    }
    // 메소드의 내용을 변경할 수 없다.
    public final void addItem( String name, String description, boolean vegetarian, double price){
        
        MenuItem menuitem = new MenuItem(name, description, vegetarian, price);
        menuItems.add(menuitem);
        
    }
    

  public Iterator<MenuItem>  createIterator() {
      // aps
      return new PancakeHouseMenuIterator(menuItems);
  }

}

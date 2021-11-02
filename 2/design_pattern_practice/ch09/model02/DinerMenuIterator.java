
package deu.cse.design_pattern.ch09.model02;

import deu.cse.desing_patttern.ch09.model01.MenuItem;
import java.util.ArrayList;

class DinerMenuIterator implements Iterator {
    
    // 배열을 알고 있어야한다.
    private final MenuItem[] items;
    private int position = 0;

    public DinerMenuIterator(  MenuItem[] items) {
        // 메뉴 아이템을 가지고 온다.
        this.items = items;
    }
    
    
    public  boolean hasNext() {
        // 포지션 위치가 아이템 사이즈 보다 작아야한다.
        return !(position >= items.length || items[position] == null);
  }

  public MenuItem next() {
      // 포지션에 있는 메뉴 아이템을 준다.
      MenuItem menuItem = items[position];
      position += 1;
      return menuItem;
  }

}

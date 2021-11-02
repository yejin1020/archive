package deu.cse.design_pattern.ch09.model02;

import deu.cse.desing_patttern.ch09.model01.MenuItem;

class DinerMenu {

    private static final int MAX_ITEMS = 6;
    private int numberOfItems = 0;
    private final MenuItem[] menuItems;
    
   public DinerMenu(){
       
       menuItems = new MenuItem[MAX_ITEMS];
       
        addItem("veggi BLT", "blah~1", true, 2.99);
        addItem("BLT", "blah~2", false, 2.99);
        addItem("Soup", "blah~3", false, 3.29);
        addItem("hot dog", "blah~4", false, 3.05);
        addItem("Steamed veggi and brown rice", "blah~5", true, 3.99);
        addItem("pasta", "blah~6", true, 3.89);
   }

    // 메소드의 내용을 변경할 수 없다.
   public final void addItem(String name, String description, boolean vegetarian,double price) {
       
           MenuItem item = new MenuItem(name, description, vegetarian, price);
        
           // 배열의 크기보다 더많이 만들 수 없다.
           if (numberOfItems >= MAX_ITEMS) {
                   System.err.println(" menu is full. cant add item to menu");
           } else {
               // 메뉴 추가하고 다음 배열을 가리킨다.
                   menuItems[numberOfItems] = item;
                   numberOfItems += 1;
           }
   }

  public Iterator< MenuItem> createIterator() {
      return new DinerMenuIterator(menuItems);
  }

}

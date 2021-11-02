
package deu.cse.design_pattern.ch09.model02;

import deu.cse.desing_patttern.ch09.model01.MenuItem;

class Waitress {
  private final PancakeHouseMenu pancakeHouseMenu;
    private final DinerMenu dinerMenu;

    public Waitress(PancakeHouseMenu pancakehouseMenu, DinerMenu dinerMenu) {
        this.pancakeHouseMenu = pancakehouseMenu;
        this.dinerMenu = dinerMenu;
    }
 
    // 메뉴판을 보여주는 동작
   public void printMenu(){
       
       Iterator <MenuItem> pancakeIterator = pancakeHouseMenu.createIterator();
       Iterator<MenuItem> dinerIterator = dinerMenu.createIterator();
       
       System.out.println("메뉴\n ----\n 아침 메뉴");
       printMenuItem(pancakeIterator);
       
       System.out.println("\n lunch menu");
       printMenuItem(dinerIterator);
   }
   
   public void printMenuItem(Iterator<MenuItem> iterator){
       while(iterator.hasNext()){
      MenuItem menuitem = iterator.next();
      System.out.print(menuitem.getName() + ",");
      System.out.print(menuitem.getPrice() + "--");
      System.out.println(menuitem.getDescription());
       }
      
   }

}

package deu.cse.design_pattern.ch06.model01;

public class Customer {
  public static void main(String[] args) {
      
      Waitress waitress = new Waitress();
      HamburgerChef chef = new HamburgerChef();
      
      // 음식을 만들 chef를 oder만들때 같이 넘겨준다.
      HamburgerOrder orderList = new HamburgerOrder(chef);
      // 웨이터가 command( orderlist)를 전달받는다
      waitress.setCommand(orderList);
      //웨이터가 오더를 전달받으면takeoder하여 세프에게 전달된다.
      // takeoder의 oderup이 호출되어 makebuger가 연결되어 chef가  햄버거를 만든다.
      waitress.takeOrder();
  }

}

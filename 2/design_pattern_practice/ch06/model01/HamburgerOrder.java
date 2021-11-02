package deu.cse.design_pattern.ch06.model01;
// 햄버거 만드는 사람이 누구인지 알고 있어야한다.
// 커맨드를 구현하는 클래스
public class HamburgerOrder implements Command {
    private HamburgerChef chef; 
    
  public HamburgerOrder(HamburgerChef chef) {
      this.chef = chef;
      //리시버인 세프가 누구인지 알기위함
  }

  public void orderUp() {
      //연결된 세프에게 makeburger호출해 버거를 만들도록한다. 
      System.out.println("햄버거 주문서가 주방에 전달됩니다.");
      chef.makeBurger();
  }
}

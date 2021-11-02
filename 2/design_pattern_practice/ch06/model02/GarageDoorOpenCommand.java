package deu.cse.design_pattern.ch06.model02;

public class GarageDoorOpenCommand implements Command {
  private GarageDoor garageDoor;

  public  GarageDoorOpenCommand(GarageDoor garageDoor) {
      this.garageDoor = garageDoor;
  }

  public void execute() {
      garageDoor.up();
  }

}

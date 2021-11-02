package deu.cse.design_pattern.ch02.model02;

public class CurrentConditionsDisplay implements Observer, DisplayElement {
  private WeatherData weatherData;
  private float temperature;
  private float humidity;

  public CurrentConditionsDisplay(WeatherData weatherData) {
      this.weatherData = weatherData;
      this.weatherData.registerObserver(this);
  }

  public void update(float temp, float humidity, float pressure) {
      this.temperature = temp;
      this.humidity = humidity;
      display();
  }

  public void display() {
      System.out.println( "Current conditions : " + temperature
      + "F degrees and" + humidity + "%humidity");
  }

}

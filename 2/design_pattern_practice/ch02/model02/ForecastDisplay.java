package deu.cse.design_pattern.ch02.model02;
        
public class ForecastDisplay implements Observer, DisplayElement {
  private float currentPressure = 29.2f;
  private float lastPressure;
  private WeatherData weatherData;

  public ForecastDisplay(WeatherData weatherData) {
      this.weatherData = weatherData;
      weatherData.registerObserver(this);
  }

  public void update(float temp, float humidity, float pressure) {
      lastPressure = currentPressure;
      currentPressure = pressure;
      display();
  }

  public void display() {
      
      System.out.print("Forcast:");
      
      if( currentPressure > lastPressure){
          System.out.println("Improving weather on the way!");
      }else if( currentPressure == lastPressure ){
          System.out.println("More of the same");
      }else if( currentPressure < lastPressure){
          System.out.println("Watch out for cooler, rainy weather");
      }
  }

}

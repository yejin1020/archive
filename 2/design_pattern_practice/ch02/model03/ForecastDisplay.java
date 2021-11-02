package deu.cse.design_pattern.ch02.model03;

import java.util.Observable;
import java.util.Observer;

public class ForecastDisplay implements Observer, DisplayElement {
  private float currentPressure = 29.2f;
  private float lastPressure;
  private WeatherData weatherData;

  public ForecastDisplay(Observable observable) {
      observable.addObserver(this);
  }

  public void update(Observable observable, Object arg) {
       if( observable instanceof WeatherData){ // WeatherData 객체만 가지고 온다, 옵저버에 여러 객체가 있을 수 있음
        WeatherData weatherData = ( WeatherData) observable;
        float pressure = weatherData.getPressure(); // weatherData에서 temperature 가지고 온다
        lastPressure = currentPressure;
        currentPressure = pressure;
        display();
       }
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

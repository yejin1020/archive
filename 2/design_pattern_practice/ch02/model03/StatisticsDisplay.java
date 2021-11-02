package deu.cse.design_pattern.ch02.model03;
import java.util.Observable;
import java.util.Observer;

public class StatisticsDisplay implements Observer, DisplayElement {
  
    private float maxTemp = 0.0f;
  private float minTemp = 200.f;
  private float tempSum = 0.0f;
  private int numReadings = 0;


  public StatisticsDisplay(Observable observable) {
      observable.addObserver(this); // observable에 등록
  }

  public void update(Observable observable, Object arg) {
       if( observable instanceof WeatherData){ // WeatherData 객체만 가지고 온다, 옵저버에 여러 객체가 있을 수 있음
        WeatherData weatherData = ( WeatherData) observable;
        float temp = weatherData.getTemperature(); // weatherData에서 temperature 가지고 온다
        
        tempSum += temp;
        numReadings++;

        if( temp > maxTemp){
         maxTemp = temp;
        }

        if( temp < minTemp){
        minTemp = temp;
        }

        display();
        }
  }

  public void display() {
       System.out.println("Avg/Max/Min temperature = " + (tempSum/numReadings)
      + "/" + maxTemp + "/" + minTemp);
  }

}

package deu.cse.design_pattern.ch02.model04;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeEvent;

class StatisticsDisplay implements 
        DisplayElement,PropertyChangeListener {
  
  private float maxTemp = 0.0f;
  private float minTemp = 200.f;
  private float tempSum = 0.0f;
  private int numReadings = 0;

   @Override
  public void propertyChange(PropertyChangeEvent evt) {

    String propertyName = evt.getPropertyName();
      // 원하는 property 이름 확인
    if(propertyName != null&& !propertyName.equals("")
            && "weather data changed".equals(propertyName)){
    WeatherData.Values newOne = (WeatherData.Values) evt.getNewValue();
    float temp = newOne.getTemperature();
    
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

  @Override
  public void display() {
       System.out.println("Avg/Max/Min temperature = " + (tempSum/numReadings)
      + "/" + maxTemp + "/" + minTemp);
  }
 }




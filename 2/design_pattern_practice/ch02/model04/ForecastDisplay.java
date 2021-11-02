package deu.cse.design_pattern.ch02.model04;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeEvent;

class ForecastDisplay implements 
        DisplayElement,PropertyChangeListener {
  
  private float currentPressure = 29.2f;
  private float lastPressure;

  public void propertyChange(PropertyChangeEvent evt) {
      
     String propertyName = evt.getPropertyName();
      // 원하는 property 이름 확인
    if(propertyName != null&& !propertyName.equals("")
            && "weather data changed".equals(propertyName)){
    WeatherData.Values newOne = (WeatherData.Values) evt.getNewValue();
    lastPressure = currentPressure;
    currentPressure = newOne.getPressure();
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

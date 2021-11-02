package deu.cse.design_pattern.ch02.model04;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeEvent;

class CurrentConditionsDisplay implements 
        DisplayElement,PropertyChangeListener {
    
    private float temperature;
    private float humidity;
     
    @Override
    public void propertyChange(PropertyChangeEvent evt) {

        String propertyName = evt.getPropertyName();
        // 원하는 property 이름 확인
        if(propertyName != null&& !propertyName.equals("")
                && "weather data changed".equals(propertyName)){
        WeatherData.Values newOne = (WeatherData.Values) evt.getNewValue();
        this.temperature = newOne.getTemperature();
        this.humidity = newOne.getHumidity();
        display();
    }
  }
    @Override
    public void display() {
         System.out.println( "Current conditions : " + temperature
      + "F degrees and" + humidity + "%humidity");
      }
}

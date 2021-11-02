package deu.cse.design_pattern.ch02.model03;

import java.util.Observable;


class WeatherData extends Observable {
    
  private float temperature;
  private float humidity;
  private float pressure;

  public WeatherData() {
  }

  public float getTemperature(){
      return temperature;
  }
  
  public float getHumidity(){
      return pressure;
  }
 
  public float getPressure(){
      return pressure;
  }
  
  public void setMeasurements(float temperature, float humidity, float pressure) {
      this.temperature = temperature;
      this.humidity = humidity;
      this.pressure = pressure;
      measurementChanged();
  }

  public void measurementChanged() {
      setChanged();
      notifyObservers();
      
  }

}

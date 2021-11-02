
package deu.cse.design_pattern.ch02.model02;

import java.util.LinkedList;


class WeatherData extends Subject {
  private float temperature;
  private float humidity;
  private float pressure;

  public WeatherData() {
      observers = new LinkedList<>();
  }

  public void registerObserver(Observer o) {
      observers.add(o);
  }

  public void removeObserver(Observer o) {
      int i = observers.indexOf(o);
      if( i >= 0 ){
          observers.remove(i);
      }
  }

  public void notifyObservers() {
      observers.forEach( (observer) -> {
          observer.update(temperature,humidity,pressure);
      });
  }

  public void setMeasurements(float temperature, float humidity, float pressure) {
      this.temperature = temperature;
      this.humidity = humidity;
      this.pressure = pressure;
      measurementChanged();
  }

  public void measurementChanged() {
      notifyObservers();
  }

}

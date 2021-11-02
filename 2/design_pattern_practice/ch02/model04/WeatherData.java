package deu.cse.design_pattern.ch02.model04;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

public class WeatherData {

// PropertyChangeSupport 생성자에 weatherdata를 넘겨준다.
private final PropertyChangeSupport pcs = new PropertyChangeSupport(this);
    
private float temperature;
private float humidity;
private float pressure;

// 내부 클래스
public class Values {
    
    private float temperature;
    private float humidity;
    private float pressure;

    public Values(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
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
}
    //PropertyChangeSupport에 listener 리스트에 추가 
    public void addPropertyChangeListener(PropertyChangeListener listener) {
        this.pcs.addPropertyChangeListener(listener);
    }
    
    //PropertyChangeSupport에 listener 리스트에서 제거 
    public void removePropertyChangeListener(PropertyChangeListener listener) {
        this.pcs.removePropertyChangeListener(listener);
    }
    
   //
  public void setMeasurements(float temperature, float humidity, float pressure) {
      
     // 현재의 값을 넣는다
    Values oldOne = new Values( this.temperature, this.humidity, this.pressure);
    // 받은 값을 넣는다
    this.temperature = temperature;
    this.humidity = humidity;
    this.pressure = pressure;
    Values newOne = new Values( this.temperature, this.humidity, this.pressure);
    
    // PropertyChangeSupport에 등록되어있는 listener에
    //"weather data changed"로 old,new 보낸다
    this.pcs.firePropertyChange("weather data changed", oldOne, newOne);
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
}

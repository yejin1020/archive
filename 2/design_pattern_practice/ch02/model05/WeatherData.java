package deu.cse.design_pattern.ch02.model05;

import java.util.concurrent.SubmissionPublisher;
import java.util.logging.Level;
import static java.util.logging.Level.SEVERE;
import java.util.logging.Logger;

class WeatherData extends SubmissionPublisher <WeatherData.Values> {
    
    private WeatherData.Values values = new WeatherData.Values(0.f, 0.f,0.f); 

    //입력된 값으로 values의 값을 바꿔준다. 
    public void setMeasurements(float temperature, float humidity, float pressure) {
        this.values.setTemperature(temperature);
        this.values.setHumidity(humidity);
        this.values.setPressure(pressure);
        
        this.submit(values); 
        try{
            Thread.sleep(150); /// 값이 완전히 전달되도록 한다.
        }catch( InterruptedException ex){
            Logger.getLogger(WeatherData.class.getName()).log(Level.SEVERE ,null,ex);
        }
    }
    
    public class Values {
        
        private float temperature;
        private float humidity;
        private float pressure;

        public Values(float temperature, float humidity, float pressure) {
            this.temperature = temperature;
            this.humidity = humidity;
            this.pressure = pressure;
        }

        public float getTemperature() {
            return temperature;
        }

        public float getHumidity() {
            return humidity;
        }

        public float getPressure() {
            return pressure;
        }

        public void setTemperature(float temperature) {
            this.temperature = temperature;
        }

        public void setHumidity(float humidity) {
            this.humidity = humidity;
        }

        public void setPressure(float pressure) {
            this.pressure = pressure;
        }
        
    }


}

package deu.cse.design_pattern.ch02.model05;

import java.util.concurrent.Flow;

public class CurrentConditionsDisplay implements
        Flow.Subscriber<WeatherData.Values>,DisplayElement {
    
    private float temperature;
    private float humidity;
    private Flow.Subscription subscription = null;
    
    @Override
    public void display() {
      System.out.println( "Current conditions : " + temperature
      + "F degrees and" + humidity + "%humidity");
    }
    
    @Override
    public void onSubscribe(Flow.Subscription subscription) {
        this.subscription = subscription;
        subscription.request(1); // 데이터 요청, 1개만
    }
    
    // 데이터를 받는 부분.
    @Override
    public void onNext(WeatherData.Values item) {
        this.temperature = item.getTemperature();
        this.humidity = item.getHumidity();
        display();
        // 다음에 오는 값을 요청한다.
        this.subscription.request(1);
    }
    
    @Override
    public void onError(Throwable throwable) {
        throw new UnsupportedOperationException("Not supported yet");
    }
    
    @Override
    public void onComplete() {
        throw new UnsupportedOperationException("Not supported yet");
    }

}

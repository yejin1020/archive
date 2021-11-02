package deu.cse.design_pattern.ch02.model04;


public class WeatherStation4 {

    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();

         CurrentConditionsDisplay currentConditions = new CurrentConditionsDisplay();
         StatisticsDisplay statisticsDisplay = new StatisticsDisplay();
         ForecastDisplay forecastDisplay = new ForecastDisplay();
         
         //propertychang에서 add한 순서대로 관리돤다.
         weatherData.addPropertyChangeListener(currentConditions);
         weatherData.addPropertyChangeListener(statisticsDisplay);
         weatherData.addPropertyChangeListener(forecastDisplay);

         weatherData.setMeasurements(80,65,30.4f);
         System.out.println("----------------------------");
         weatherData.setMeasurements(82,70,29.2f);
         System.out.println("----------------------------");
         
         //Property에서 currentConditionslistener를 제거한다. 
         weatherData.removePropertyChangeListener(currentConditions);
         weatherData.setMeasurements(78,90,29.2f);
         System.out.println("----------------------------");        
         
    }
}

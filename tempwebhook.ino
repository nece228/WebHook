// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

// Define Pins
    #define DHTPIN 3     // what pin we're connected to

// Setup Sensor
    #define DHTTYPE DHT22		// DHT 22 (AM2302)

    DHT dht(DHTPIN, DHTTYPE);


void setup() 
{

    dht.begin();		// Startup the sensor
    
}

void loop(){

    // hold up    
        delay(2000); // let everything power up for a bit
        
    // grab some data	
        float humidity = dht.getHumidity();
        float tempc = dht.getTempCelcius();
        float dewptc = dht.getDewPoint();
        float dewptf = (dewptc* 9 / 5 + 32);
       
        //Publish only the temperature
        Particle.publish("temp", String(tempc), PRIVATE);

    //Hold up    
    delay(10000);
} 

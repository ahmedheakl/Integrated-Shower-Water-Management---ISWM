#include <BobaBlox.h>
int Valve = 7;
#include <dht.h>
dht DHT;
#define DHT11_PIN 13
int val;
Knob myKnob(4);         // Knob is connected to Analog pin #1 (digital pin #2)
int knobValue;
void setup () 
{
  pinMode( Valve, OUTPUT);
  Serial.begin(9600);
}
void loop ()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  int temprature = DHT.temperature;
  Serial.println(temprature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
  knobValue = myKnob.value();
  Serial.print(map(knobValue, 0, 1023, 25, 40));
  if (temprature >= map(knobValue, 0, 1023, 25, 40))
  {
    digitalWrite(Valve, HIGH);
  }
  else
  { digitalWrite(Valve, LOW);
  }
}


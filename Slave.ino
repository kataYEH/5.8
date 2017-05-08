
#include<dht.h>
dht DHT;
#include<Wire.h>

#define pin 2
void setup() 
{
    Serial.begin(9600);
    Wire.begin(8);
   Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
   
}
void requestEvent()
{
  int i;
  char aa[5];
  char bb[5];
 
  DHT.read11(pin);
  float h = DHT.humidity/3;
  float t = DHT.temperature*2;
  dtostrf(h,5,2,aa);
 
  Wire.write("hum= ");
  Wire.write(aa);
  dtostrf(t,5,2,bb);
  Wire.write("  t= ");
  Wire.write(bb);
  Wire.write("       ");
  }

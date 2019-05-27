#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial sgps(2, 3);

void setup()
{
  Serial.begin(9600);
  sgps.begin(9600);
}

void loop()
{
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
float mylat,mylong;
      gps.f_get_position(&mylat, &mylong);
      Serial.print("Latitude :");
      Serial.println(mylat, 10);
      Serial.print("Longitude:");
      Serial.println(mylong, 10);
    }
  }
}

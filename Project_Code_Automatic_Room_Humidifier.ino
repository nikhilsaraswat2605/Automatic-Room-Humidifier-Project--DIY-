#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte deg[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

dht DHT;

float hum;
float temp;

void setup(){
  lcd.createChar(0,deg);
  lcd.begin(16,2);
  pinMode(7,OUTPUT);
}

void loop(){
  int chk = DHT.read22(8);		//Read data and store it to variables hum and temp
  hum = DHT.humidity;
  temp= DHT.temperature;		//Print temp and humidity values to LCD
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.write(byte(0));
  lcd.print("C");
  
  if(hum<=40)
  {
    digitalWrite(7,HIGH);
  }
  
  delay(2000);
}
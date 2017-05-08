#include<Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int t = 0;
int wordn = 0;
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("04050343 04050794 START");
  lcd.begin(20, 2); 

lcd.cursor(); // 游標
//lcd.blink(); // 游標閃爍
}

void loop() 
{
   Wire.requestFrom(8, 20);
   while(Wire.available())
   {
    char val = Wire.read();
    Serial.print(val);
       if(32 <= val && val <= 126)
       {
          if(wordn == MAXword)
          {
            wordn = 0;
            lcd.clear();
          }
        lcd.write(val);
        wordn++;
        lcd.setCursor((wordn%20),(wordn/20));
        }
   }
    Serial.println("");
    delay(2000);
}

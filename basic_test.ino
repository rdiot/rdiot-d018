/* Tower Pro SG90 Micro Servo (SG90) [D018] : http://rdiot.tistory.com/280 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
Servo myservo; 
int servoPin = 12;
int pos = 0; 

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  myservo.attach(servoPin); 
  delay(1000);

  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("D018:SG90 Servo");

  for(pos = 0; pos < 180; pos += 1) 
  { 
    myservo.write(pos);
    lcd.setCursor(0,1);
    lcd.print("pos0~179=" + (String)pos + "  " );
    delay(0); // Control Speed by delay time.
  }

  for(pos = 180; pos>=1; pos-=1)
  { 
    myservo.write(pos); 
    lcd.setCursor(0,2);
    lcd.print("pos180~1=" + (String)pos + "  " );
    delay(0); 
  } 
}

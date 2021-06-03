
#include <Wire.h>
#include <LiquidCrystal_I2C.h>// initialize the library with the numbers of the interface pins

#include <Servo.h> //includes the servo library

Servo myservo1;

/*------Setez pin-i unde am conectat LCD------*/
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

/*------Iau adresa de la LCD-ul meu------*/
const int i2c_addr = 0x27;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

/*------Configurarea pinilor conectate pe placa UNO R3------*/

/*---Senzori de intrare pe pinul digital 2 respectiv iesire pe pinul digital 4---*/
int intrare = 2;
int iesire = 4;

/*---Senzori pentru locuri de parcare conectat la pinii digital 5,6,7,8---*/
int loc1 =5;
int loc2 =6;
int loc3 =7;
int loc4 =8;

/*---LED-uri conectat la pinii digital 9,10,11,12---*/
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;

/*---Doua variabile in care stochez Spatiul TOTAl in parcare si spatiul ramas---*/
int Total = 4;
int Spatiul;

/*---Doua variabile temporare---*/
int temp1 = 0;
int temp2 = 0;

void setup() {

/*------Configurez informatilor de input de la senzorii conectat la pinii respectiv------*/  
pinMode(intrare, INPUT);
pinMode(iesire, INPUT);
pinMode(loc1, INPUT);
pinMode(loc2, INPUT);
pinMode(loc3, INPUT);
pinMode(loc4, INPUT);

/*------Configurez servo-motorul conectat pe digita pin 3------*/  
myservo1.attach(3);
myservo1.write(100);

/*------Configurez informatilor de output, care in cazul meu sunt doar 4 LED-uri------*/
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

/*------Configurez LCD-ul pentru a afisa informatile necesare------*/
lcd.begin(16, 2);  
lcd.setCursor (0,0);
lcd.print("  Parcare  ");
lcd.setCursor (0,1);
lcd.print("     Inteligenta     ");
delay (2000);
lcd.clear();  

Spatiul = Total;
}

void loop(){ 

/*------Actionare bara de intrare/iesire din parcare si informatile afisate pe LCD.
        Daca toate locuri sunt ocupate, bara nu mai deschide si se afiseaza pe LCD
        ca nu mai sunt locuri------*/
        
if(digitalRead (intrare) == LOW && temp1==0){
  if(Spatiul>0){
    temp1=1;
    if(temp2==0){
      myservo1.write(0); 
      Spatiul = Spatiul-1;
      }
  }else{
    lcd.setCursor (0,0);
    lcd.print(" Nu mai este loc ");  
    lcd.setCursor (0,1);
    lcd.print("    disponibil    "); 
    delay (1000);
    lcd.clear(); 
  }
}

if(digitalRead (iesire) == LOW && temp2==0){
  temp2=1;
  if(temp1==0){
    myservo1.write(0); 
    Spatiul = Spatiul+1;
    }
}

if(temp1==1 && temp2==1){
  delay (1000);
  myservo1.write(100);
  temp1=0; 
  temp2=0;
}

lcd.setCursor (0,0);
lcd.print("Spatiul Total: ");
lcd.print(Total);

lcd.setCursor (0,1);
lcd.print("Disponibil: ");
lcd.print(Spatiul);

/*------Actionare LED-uri pe locuri de parcare-------*/

if(digitalRead(loc1) == HIGH)
    digitalWrite(led1, LOW);
  else
    digitalWrite(led1, HIGH);

if(digitalRead(loc2) == HIGH)
    digitalWrite(led2, LOW);
  else
    digitalWrite(led2, HIGH);

if(digitalRead(loc3) == HIGH)
    digitalWrite(led3, LOW);
  else
    digitalWrite(led3, HIGH);

if(digitalRead(loc4) == HIGH)
    digitalWrite(led4, LOW);
  else
    digitalWrite(led4, HIGH);            
}

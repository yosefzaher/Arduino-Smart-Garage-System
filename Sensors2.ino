/****************************************************************************************
 * @name    : Sernsors.ino
 * @author  : ENG.Yosef Zaher / yousefalmarasi / mohamed tarek / yousef elnagar / marwan elshahiy / yousry alsaid 
 * @brief   : I Made The Hall File ,This File Is The Seneor Project
              Project        -> Smart Garage System 
              We Use Sensors -> {DHT11 ,IR ,LDR} 
              DHT11          -> To detect if there is a Fire occures in the 
                                Garage and Immediately Active The Emergency Mode
              IR             -> We Use Two IR Sensors to Put them One in Entery Gate 
                                To Detect if Car is Go on The Garage or Not     
                                And The Second One on the Outter Gate To detect if 
                                Car Go out of The garage
              LDR            -> To Active Lamppost System in Night                               
****************************************************************************************/
/*Include Library Section Start*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <DHT.h> 
/*Include Library Section End*/

/*Macros Section Start*/
#define ENTRY_GATE_PIN 2   // Pin for entry gate IR sensor
#define EXIT_GATE_PIN 3    // Pin for exit gate IR sensor
#define MAX_SLOTS 4        // Maximum parking slots
#define DHTTYPE DHT11 //DHT Sensor Type
#define DHT11_Pin A1 //DHT Sensor Pin

//Alarm System Pins 
#define BUZZER1 0 
#define BUZZER2 1 
/**********************/


//Lapposts System Pins
#define Lamppost1 8
#define Lamppost2 9
#define Lamppost3 10
#define Lamppost4 11
#define Lamppost5 12
/**********************/

#define LDR A0 // LDR Sensor Pin
/*Macros Section End*/

/*Global Variable Section Start*/
Servo entryGateServo;     // Servo motor for entry gate
Servo exitGateServo;      // Servo motor for exit gate
DHT dht11(DHT11_Pin ,DHTTYPE) ;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address, columns, rows

unsigned int Ldr_Val = 0 ; //Variable To Read LDR Sensor
float Dht11_Val = 0.0 ;  //Variable To Read DHT11 Sensor 
int carCount = 0;  // Variable to count cars
/*Global Variable Section End*/

/*Setup Function Section Start*/
void setup() {

  /*Make The LDR , IR Sensors Pins INPUT*/  
  pinMode(ENTRY_GATE_PIN, INPUT);
  pinMode(EXIT_GATE_PIN, INPUT);
  pinMode(LDR ,INPUT) ;
  /**************************************/
  
  /*Make The Alarm System Pins OUTPUT*/
  pinMode(BUZZER1 ,OUTPUT) ;
  pinMode(BUZZER2 ,OUTPUT) ;
  /**************************************/

  /*Make Lampposts System Pins OUTPUT Pins*/
  pinMode(Lamppost1 ,OUTPUT) ;
  pinMode(Lamppost2 ,OUTPUT) ;
  pinMode(Lamppost3 ,OUTPUT) ;
  pinMode(Lamppost4 ,OUTPUT) ;
  /***************************************/

  entryGateServo.attach(4);  // Servo motor pin for entry gate
  exitGateServo.attach(5);   // Servo motor pin for exit gate
  
  dht11.begin() ; //DHT11 Sensor Begin
  entryGateServo.write(0);   // Close entry gate
  exitGateServo.write(0);    // Close exit gate
  lcd.init();  // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
 
  // Decoration For LCD Start
  lcd.setCursor(4, 0);
  lcd.print("WELCOME");
  lcd.setCursor(0, 1);
  lcd.print(" SMART  PARKING");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("There Are (   )");
  lcd.setCursor(0, 1);
  lcd.print("Slots Available");
  /***************************************/  
  updateLCD(); //Updating The LCD
}
/*Setup Function Section End*/

/*Loop Function Section Start*/
void loop() {
  delay(1000); //delay Time For 1 Second
  Ldr_Val = analogRead(LDR) ; // Read The Analog Value of The LDR Sensor
  Dht11_Val = dht11.readTemperature() ; //Read The Value Of the Temprature
  if(Dht11_Val >= 30) //If Yes 
  {
    //Turn On the Alarm System
    digitalWrite(BUZZER1 ,HIGH) ;
    digitalWrite(BUZZER2 ,HIGH) ;
    delay(50) ;
    digitalWrite(BUZZER1 ,LOW) ;
    digitalWrite(BUZZER2 ,LOW) ;
    delay(50) ;
    digitalWrite(BUZZER1 ,HIGH) ;
    digitalWrite(BUZZER2 ,HIGH) ;
    delay(50) ;

  } else //If NO
  {
    //Turn Off the Alarm System 
    digitalWrite(BUZZER1 ,LOW) ;
    digitalWrite(BUZZER2 ,LOW) ;
  }
  if(Ldr_Val <= 500) //If Yes
    { 
      Lampposts_ON() ; //Turn On The Lampposts System
    }
    else //If NO
    {
      Lampposts_OOF() ; //Turn OFF The Lampposts System
    }
  // Check if a car is entering
  if (digitalRead(ENTRY_GATE_PIN) == LOW && carCount < MAX_SLOTS) {
    delay(1000);  // Debounce delay
    if (digitalRead(ENTRY_GATE_PIN) == LOW) {
      entryGateServo.write(90);  // Open entry gate
      delay(2000);  // Time for car to pass
      entryGateServo.write(0);   // Close entry gate
      carCount++;
      updateLCD();
    }
  } 

  // Check if a car is exiting
  if (digitalRead(EXIT_GATE_PIN) == LOW && carCount > 0) {
    delay(1000);  // Debounce delay
    if (digitalRead(EXIT_GATE_PIN) == LOW) {
      exitGateServo.write(90);  // Open exit gate
      delay(2000);  // Time for car to pass
      exitGateServo.write(0);   // Close exit gate
      carCount--;
      updateLCD();
    }
  }
}
/*Loop Function Section End*/

/*SubPrograms Section Start*/

/**
  * @brief  :  Function To Update The Text on the LCD if Car in or out from Garage
  * @param  :  Void Param "There is No any Params"
  * @retval :  Void Return Value "There is no any Thing to Return"
**/
void updateLCD(void) {
  lcd.setCursor(12, 0);
  lcd.print(" ");  // Clear previous count
  lcd.setCursor(12, 0);
  lcd.print(MAX_SLOTS-carCount);
}

/**
  * @brief  :  Function To Turn On The Lampposts System
  * @param  :  Void Param "There is No any Params"
  * @retval :  Void Return Value "There is no any Thing to Return"
**/
void Lampposts_ON(void)
{
  digitalWrite(Lamppost1 ,HIGH) ;
  digitalWrite(Lamppost2 ,HIGH) ;
  digitalWrite(Lamppost3 ,HIGH) ;
  digitalWrite(Lamppost4 ,HIGH) ;
  digitalWrite(Lamppost5 ,HIGH) ;

}

/**
  * @brief  :  Function To Turn OOF The Lampposts System
  * @param  :  Void Param "There is No any Params"
  * @retval :  Void Return Value "There is no any Thing to Return"
**/
void Lampposts_OOF(void)
{
  digitalWrite(Lamppost1 ,LOW) ;
  digitalWrite(Lamppost2 ,LOW) ;
  digitalWrite(Lamppost3 ,LOW) ;
  digitalWrite(Lamppost4 ,LOW) ;
  digitalWrite(Lamppost5 ,LOW) ;

}
/*SubPrograms Section End*/



/*******************************************************************************************
*   @author                @date            @brief                                         *                 
*   ENG.Yosef Zaher        9May2024         I Made The Code of All Sensors                 *                                           
*   ENG.Marwan Elshehawy   10May2024        Update The Servo Code To Solve The Problem     *
                                            Of The Bouncing Of the Servo                   *                        
********************************************************************************************/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "input.h"
#include "math.h"
#include "output.h"

const byte ROWS = 4; 
const byte COLS = 4; 

char KeyPad[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '#', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad calculatorPad = Keypad(makeKeymap(KeyPad), rowPins, colPins, ROWS, COLS); 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 (Cooperate with 3 short circuit caps) for a 16 chars and 2 line display)

double stack[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();

  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  OPERAND op = input( stack, calculatorPad, lcd );
  math( stack, op );
  output( stack, lcd );
  
//  char calcPadOld = 0;
//  char calcPad = calculatorPad.getKey();
//  
////  if (calcPad == '#'){
////    //Serial.println();
////    lcd.print(' ');
////  } else lcd.print(calcPad);
//  //Serial.print(calcPad);
//  if(calcPad != calcPadOld){
//    lcd.print(calcPad);
//  }
//  if(calcPad == '#'){
//    lcd.clear();
//  }
//  calcPadOld = calcPad;
}
  

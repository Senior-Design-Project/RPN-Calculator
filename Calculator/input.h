#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <string.h>

enum OPERAND {PLUS, MINUS, TIMES, DIVIDE};

bool isStringValid(char string[]) {
  // Check the string to search for multiple decimal points, which is invalid
  Serial.print(string);
  Serial.print('\n');
  char str[17];
  strcpy(str,string);
  char *temp = strrchr(str, '.');
  if( temp != NULL ) {
    str[temp-str] = '\0';
    Serial.print(str);
    temp = strchr(str, '.');
    if( temp != NULL )
      return false;
  }
  return true;
};

void printError(LiquidCrystal_I2C &lcd) {
  lcd.clear();
  lcd.print("Ope!");
  return;
};

OPERAND input( double (&stack)[4], Keypad &calculatorPad, LiquidCrystal_I2C &lcd ) {
  char string[17] = "";
  char blank[17] = "\0";
  while(1) {
    char pressed;
    pressed = calculatorPad.getKey();
    switch(pressed) {
      case '#':
        if( isStringValid( string ) ) {
          // Add to stack
          stack[3] = stack[2];
          stack[2] = stack[1];
          stack[1] = stack[0];
          stack[0] = atof(string);
        } else {
          printError(lcd);
        }
        strcpy(string, blank);
        break;
      case '+':
        // Return with PLUS
        if( isStringValid( string ) ) {
          if( strcmp(string, blank) != 0) {
            stack[3] = stack[2];
            stack[2] = stack[1];
            stack[1] = stack[0];
            stack[0] = atof(string);
          }
          return PLUS;
        }
        printError(lcd);
        strcpy(string, blank);
        break;
      case '-':
        // Return with MINUS
        if( isStringValid( string ) ) {
          if( strcmp(string, blank) != 0 ) {
            stack[3] = stack[2];
            stack[2] = stack[1];
            stack[1] = stack[0];
            stack[0] = atof(string);
            strcpy(string, blank);
          }
          return MINUS;
        }
        printError(lcd);
        strcpy(string, blank);
        break;
      case '*':
        // Return with TIMES
        if( isStringValid( string ) ) {
          if( strcmp(string, blank) != 0 ) {
            stack[3] = stack[2];
            stack[2] = stack[1];
            stack[1] = stack[0];
            stack[0] = atof(string);
            strcpy(string, blank);
          }
          return TIMES;
        }
        printError(lcd);
        strcpy(string, blank);
        break;
      case '/':
        // Return with DIVIDE
        if( isStringValid( string ) ) {
          if( strcmp(string, blank) != 0 ) {
            stack[3] = stack[2];
            stack[2] = stack[1];
            stack[1] = stack[0];
            stack[0] = atof(string);
            strcpy(string, blank);
          }
          return DIVIDE;
        }
        printError(lcd);
        strcpy(string,blank);
        break;
      case 0:
        // Null character, do nothing
        break;
      default:
        // Add character to the string
        int len = strlen(string);
        string[len] = pressed;
        string[len+1] = '\0';
        lcd.clear();
        lcd.print(string);
        break;
    }
  }
};

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

enum OPERAND {PLUS, MINUS, TIMES, DIVIDE};

OPERAND input( double (&stack)[4], Keypad &calculatorPad, LiquidCrystal_I2C &lcd ) {
  char string[17] = "";
  char blank[17] = "\0";
  while(1) {
    char pressed;
    pressed = calculatorPad.getKey();
    switch(pressed) {
      case '#':
        // Add to stack
        stack[3] = stack[2];
        stack[2] = stack[1];
        stack[1] = stack[0];
        stack[0] = atof(string);
        strcpy(string, blank);
        break;
      case '+':
        // Return with PLUS
        if( strcmp(string, blank) != 0 ) {
          stack[3] = stack[2];
          stack[2] = stack[1];
          stack[1] = stack[0];
          stack[0] = atof(string);
          strcpy(string, blank);
        }
        return PLUS;
        break;
      case '-':
        // Return with MINUS
        if( strcmp(string, blank) != 0 ) {
          stack[3] = stack[2];
          stack[2] = stack[1];
          stack[1] = stack[0];
          stack[0] = atof(string);
          strcpy(string, blank);
        }
        return MINUS;
        break;
      case '*':
        // Return with TIMES
        if( strcmp(string, blank) != 0 ) {
          stack[3] = stack[2];
          stack[2] = stack[1];
          stack[1] = stack[0];
          stack[0] = atof(string);
          strcpy(string, blank);
        }
        return TIMES;
        break;
      case '/':
        // Return with DIVIDE
        if( strcmp(string, blank) != 0 ) {
          stack[3] = stack[2];
          stack[2] = stack[1];
          stack[1] = stack[0];
          stack[0] = atof(string);
          strcpy(string, blank);
        }
        return DIVIDE;
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

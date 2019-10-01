#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

enum OPERAND {PLUS, MINUS, TIMES, DIVIDE};

OPERAND input( double (&stack)[4], Keypad &calculatorPad, LiquidCrystal_I2C &lcd ) {
  char string[17] = "";
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
        strcpy(string, "");
        break;
      case '+':
        // Return with PLUS
        stack[3] = stack[2];
        stack[2] = stack[1];
        stack[1] = stack[0];
        stack[0] = atof(string);
        strcpy(string, "");
        return PLUS;
        break;
      case '-':
        // Return with MINUS
        stack[3] = stack[2];
        stack[2] = stack[1];
        stack[1] = stack[0];
        stack[0] = atof(string);
        strcpy(string, "");
        return MINUS;
        break;
      case '*':
        // Return with TIMES
        stack[3] = stack[2];
        stack[2] = stack[1];
        stack[1] = stack[0];
        stack[0] = atof(string);
        strcpy(string, "");
        return TIMES;
        break;
      case '/':
        // Return with DIVIDE
        stack[3] = stack[2];
        stack[2] = stack[1];
        stack[1] = stack[0];
        stack[0] = atof(string);
        strcpy(string, "");
        return DIVIDE;
        break;
      case 0:
        // Null character, do nothing
        break;
      default:
        // Add character to the string
        string[strlen(string)] = pressed;
        lcd.clear();
        lcd.print(string);
        break;
    }
  }
};

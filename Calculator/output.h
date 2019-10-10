#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void output( double (&stack)[4], LiquidCrystal_I2C &lcd ) {
  lcd.clear();
  char string[17] = "";
  char error[] = "And I ope!";
  // Check the size of the number
  if(!isinf(stack[0]) && !isnan(stack[0])){
  if( abs(stack[0]) >= 1000000 || abs(stack[0]) <= 0.001 ) {
    // Scientific Notation
    dtostre( stack[0], string, 7, DTOSTR_UPPERCASE | DTOSTR_ALWAYS_SIGN );
  } else {
    dtostrf( stack[0], -16, 2, string ); // Negative for left aligned
  }
  // https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__stdlib_1ga060c998e77fb5fc0d3168b3ce8771d42.html
  lcd.print(string);
  } else lcd.print(error);
  return;
}

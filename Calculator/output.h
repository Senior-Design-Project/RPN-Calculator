#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void output( double (&stack)[4], LiquidCrystal_I2C &lcd ) {
  lcd.clear();
  char string[17] = "";
  dtostrf( stack[0], -16, 2, string ); // Negative for left aligned
  // https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__stdlib_1ga060c998e77fb5fc0d3168b3ce8771d42.html
  lcd.print(string);
  return;
}

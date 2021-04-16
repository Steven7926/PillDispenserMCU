#include <Stepper.h>
#include <SPI.h>
// change this to the number of steps on your motor
#define STEPS 25
 
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);
 
 
void setup()
{

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  // turn on interrupts
  //SPI.attachInterrupt();
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(45);
}
 
void loop()
{
  byte in_byte;
  byte return_val = 0x80;
 
 
  if ((SPSR & (1 << SPIF)) != 0)
  {
    in_byte = SPDR;
   
    Serial.println("Forward");
    stepper.step(STEPS);
   
    SPDR = return_val;
  }

}
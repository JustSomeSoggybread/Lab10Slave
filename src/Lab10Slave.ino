SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include <Wire.h>
#include "oled-wing-adafruit.h"

/*
      ## SLAVE ##
*/

void receiveEvent(int howMany){
    char x = Wire.read();

    if (x == '1'){
        digitalWrite(D7, HIGH);
    }
    else if (x == '0'){
        digitalWrite(D7, LOW);
    }

    else if (x == '?'){
        requestEvent();
    }

    //digitalWrite(D7, HIGH);
    
}

void requestEvent(){
    if (digitalRead(D6) == HIGH){
            Wire.write('1');

        }

        else{
            Wire.write('0');
        }
    
    //digitalWrite(D7, HIGH);
}

// setup() runs once, when the device is first turned on.
void setup(){
  // Put initialization like pinMode and begin functions here.

  pinMode(D7, OUTPUT);
  pinMode(D6, INPUT);

  
  Wire.begin(0x2A);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

}

// loop() runs over and over again, as quickly as it can execute.
void loop(){
  // The core of your code will likely live here.
  
}


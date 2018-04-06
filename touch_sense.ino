#include <CapacitiveSensor.h>

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define NUM_OF_SAMPLES  10   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   150  // Capactive reading that triggers a note (adjust to fit your needs)//depends on the resistace used in the circuit like we used 2.2mohm
#define NUM_OF_KEYS     7    // Number of keys that are on the keyboard

// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)
#define delay_time 500
// You need to declare as many as the value of NUM_OF_KEYS
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(11), CS(12)};
//this declaration is as per the library we included above ie. CapacitiveSensor.h

void setup() {
  Serial.begin(9600);
  // Turn off autocalibrate on all channels:
  for(int i=0; i<NUM_OF_KEYS; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF); 
    //sets every key of the piano to null or not touched (defines that the every single key is not touched)
  }
  Serial.println(delay_time);
  //just printing to check if the python script is taking the values from the arduino or not
}  

void loop() {
  // Loop through each key:
  for (int i = 0; i < NUM_OF_KEYS; ++i) {
    if(touched(i)) {
       //checks that if the key is pressed ot not
      Serial.println(i);
      delay(delay_time);
    }
  }
  // the above loop is to print the key number which is pressed, with a delay of 500 
}

bool touched(int i) {
  // If the capacitance reading is greater than the threshold, return true
  if (keys[i].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD) {
    //while using 2.2ohm resistance we took 150 as threshold value so if the key is pressed the value of the NUM_OF_SAMPLES will decrease thus detecting the touch
    return true;
  }
  else {
    return false;
  }
}

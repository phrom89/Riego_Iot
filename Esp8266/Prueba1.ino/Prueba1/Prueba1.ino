
#include secrets.h


#define LED 2
#define SW1 0


int Button_State;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(SW1, INPUT);
}

// the loop function runs over and over again forever
void loop() {


  Button_State = digitalRead(SW1);

  if(Button_State == HIGH){

    digitalWrite(LED, HIGH);

  }

  else {

    digitalWrite(LED, LOW); 


  }
                    // wait for a second
}

//Components' GPIO pins
int opened_closed_circuit_listener_pin = 2;
int led_red_pin = 3;
int led_green_pin = 4;
int buzzer_pin = 9; //the buzzer (speaker)

int opened_closed_circuit_state = 0; //contains the state of the

void setup() {
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(opened_closed_circuit_listener_pin, INPUT);

  //Blinking LED and making some noise during Setup (startup)
  digitalWrite(led_green_pin, HIGH);
  digitalWrite(led_red_pin, LOW);
  tone(buzzer_pin, 523, 150);
  delay(200);

  digitalWrite(led_green_pin, LOW);
  digitalWrite(led_red_pin, HIGH);
  tone(buzzer_pin, 659, 150);
  delay(200);

  digitalWrite(led_green_pin, HIGH);
  digitalWrite(led_red_pin, LOW);
  tone(buzzer_pin, 784, 150);
  delay(200);

  //Silencing the buzzer
  noTone(buzzer_pin);

  //Turning off the LED
  digitalWrite(led_green_pin, LOW);
  digitalWrite(led_red_pin, LOW);

}

void loop() {
  opened_closed_circuit_state = digitalRead(opened_closed_circuit_listener_pin);

  if (opened_closed_circuit_state == HIGH) {
    // turn LED and buzzer ON
    digitalWrite(led_red_pin, LOW);
    digitalWrite(led_green_pin, HIGH);

    tone(buzzer_pin, 1000, 10);
  } else {
    // turn LED and buzzer OFF
    digitalWrite(led_red_pin, HIGH);
    digitalWrite(led_green_pin, LOW);
  }
}

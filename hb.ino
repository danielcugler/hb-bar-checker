int opened_closed_circuit_listener_pin = 2;
int led_red_pin = 4;
int led_green_pin = 3;
int buzzer_pin = 9;

int opened_closed_circuit_state = 0;

void setup() {
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(opened_closed_circuit_listener_pin, INPUT);

  // Sinal de inicialização (LEDs piscando e buzzer apitando)
  digitalWrite(led_green_pin, LOW);
  digitalWrite(led_red_pin, HIGH);
  tone(buzzer_pin, 523, 150);
  delay(200);

  digitalWrite(led_green_pin, HIGH);
  digitalWrite(led_red_pin, LOW);
  tone(buzzer_pin, 659, 150);
  delay(200);

  digitalWrite(led_green_pin, LOW);
  digitalWrite(led_red_pin, HIGH);
  tone(buzzer_pin, 784, 150);
  delay(200);

  // Desliga tudo ao finalizar setup
  noTone(buzzer_pin);
  digitalWrite(led_green_pin, LOW);
  digitalWrite(led_red_pin, LOW);
}

void loop() {
  opened_closed_circuit_state = digitalRead(opened_closed_circuit_listener_pin);

  if (opened_closed_circuit_state == HIGH) {
    // Pino 2 ACIONADO → buzzer OFF, luz verde ON
    noTone(buzzer_pin);
    digitalWrite(led_red_pin, LOW);
    digitalWrite(led_green_pin, HIGH);
  } else {
    // Pino 2 DESACIONADO → buzzer ON, luz vermelha ON
    tone(buzzer_pin, 1000); // buzzer ativo
    digitalWrite(led_red_pin, HIGH);
    digitalWrite(led_green_pin, LOW);
  }
}

#define LED_PIN_1 9
#define LED_PIN_2 10
#define LED_PIN_3 11

unsigned long startTime = 0;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(LED_PIN_1, OUTPUT); // Configura o pino do LED 1 como saída
  pinMode(LED_PIN_2, OUTPUT); // Configura o pino do LED 2 como saída
  pinMode(LED_PIN_3, OUTPUT); // Configura o pino do LED 3 como saída
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readString(); // Lê o comando serial
    Serial.print("Opção recebida: ");
    Serial.println(comando);

    // Movimenta o motor 1 para angulo de 0 a 115 graus se receber "vidro"
    if (comando == "vidro") {
      digitalWrite(LED_PIN_1, HIGH);
      delay(3000); // Espera 30 segundos
      digitalWrite(LED_PIN_1, LOW); // Apaga o LED 1
    }
    // Movimenta o motor 2 para angulo de 0 a 115 graus se receber "plastico"
    else if (comando == "plastico") {
      digitalWrite(LED_PIN_2, HIGH);
      delay(3000); // Espera 30 segundos
      digitalWrite(LED_PIN_2, LOW); // Apaga o LED 2
    }
    // Movimenta o motor 3 para angulo de 0 a 115 graus se receber "lata"
    else if (comando == "lata") {
      digitalWrite(LED_PIN_3, HIGH);
      delay(3000); // Espera 30 segundos
      digitalWrite(LED_PIN_3, LOW); // Apaga o LED 3
    }
    // Se receber "x", acende todos os LEDs por 3 segundos antes de sair
    else if (comando == "x") {
      startTime = millis(); // Registra o tempo de início
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      while (millis() - startTime < 3000) {
        // Aguarda 3 segundos
      }
      digitalWrite(LED_PIN_1, LOW); // Apaga o LED 1
      digitalWrite(LED_PIN_2, LOW); // Apaga o LED 2
      digitalWrite(LED_PIN_3, LOW); // Apaga o LED 3
    }
  }
}

#include <Servo.h>

#define SERVO_PIN_1 9
#define SERVO_PIN_2 10
#define SERVO_PIN_3 11

Servo servo_1;
Servo servo_2;
Servo servo_3;

bool should_exit = false;

// Variáveis para armazenar as posições iniciais dos servos
int initial_position_1 = 0;
int initial_position_2 = 0;
int initial_position_3 = 0;

void setup() {
  Serial.begin(9600);           // Inicia a comunicação serial
  servo_1.attach(SERVO_PIN_1);  // Configura o pino do servo 1
  servo_2.attach(SERVO_PIN_2);  // Configura o pino do servo 2
  servo_3.attach(SERVO_PIN_3);  // Configura o pino do servo 3
}

void loop() {
  if (Serial.available() > 0) {
    servo_1.write(0);
    servo_2.write(0);
    servo_3.write(0);
    String comando = Serial.readStringUntil('\n');  // Lê o comando serial
    comando.trim();                                 // Remove espaços em branco no início e no final do comando

    // Verifica qual comando foi recebido e movimenta os servos conforme necessário
    if (comando == "vidro") {
      servo_1.write(115);  // Mova o servo 1 para 115 graus
      delay(3000);         // Aguarda 3 segundos
      servo_1.write(0);    // Retorna o servo 1 para a posição 0
      delay(2000);         // Aguarda 3 segundos
      servo_1.detach();    // Desativa o servo 1
    } else if (comando == "plastico") {
      servo_2.write(115);  // Mova o servo 2 para 115 graus
    } else if (comando == "lata") {
      servo_3.write(115);  // Mova o servo 3 para 115 graus
    } else if (comando == "x") {
      // Se receber "x", encerre o programa
      should_exit = true;
    } else {
      // Se o comando não for reconhecido, imprima uma mensagem de erro
      Serial.println("Comando inválido!");
    }
  }

  // Verifica se o programa deve ser encerrado e retorna os servos para a posição 0
  if (should_exit) {
    servo_1.write(0);  // Retorna o servo 1 para a posição 0
    servo_2.write(0);  // Retorna o servo 2 para a posição 0
    servo_3.write(0);  // Retorna o servo 3 para a posição 0

    servo_2.detach();  // Desativa o servo 2
    servo_3.detach();  // Desativa o servo 3
    while (true) {
      // Loop vazio para manter o programa ativo, mas não faz nada
    }
  }
}

#include <Servo.h>  // incluindo a biblioteca

Servo servo1;  // criando os objetos servos
Servo servo2;

int VRX, VRY;  // variáveis que vão receber os valores analógicos dos joysticks ou potenciômetros

void setup() {
  servo1.attach(5);  // ligando o servo na porta digital 5
  servo2.attach(6);  // ligando o servo na porta digital 5
  servo1.write(90);  // coloca o servo na posição de 90 graus
  servo2.write(90);
}

void loop() {
  VRX = analogRead(3);              // VRX recebe o valor lido na porta analógica 3
  VRY = analogRead(4);              // VRX recebe o valor lido na porta analógica 3
  VRX = map(VRX, 0, 1023, 0, 180);  // remapeia por interpolação o valor de VRX
  // ou seja, compara o valor de analogRead com um valor em graus que está entre 0 e 180
  VRY = map(VRY, 0, 1023, 0, 180);
  servo1.write(VRX);  // posiciona o servo na posição lida
  servo2.write(VRY);
  delay(15);  // aguarda um tempo de 15 milissegundos
}
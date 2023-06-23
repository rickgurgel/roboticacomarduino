#include <HCSR04.h> // incluindo a biblioteca do sensor ultrassom
#include <LiquidCrystal_I2C.h> // incluindo a biblioteca do lcd com módulo I2C

HCSR04 hc(7,6); // cria o objeto sensor de ultrassom
float distancia; // variável para receber o valor da distância medida pelo sensor
LiquidCrystal_I2C lcd(0x27, 16, 2); // cria o objeto lcd

void setup() {
  Serial.begin(9600);
  lcd.init(); // iniciando o lcd
  lcd.backlight(); // ligando o backlight do lcd
}

void loop() {
  distancia = hc.dist(); // distancia recebe o valor medido pelo sensor EM CENTÍMETROS
  lcd.clear(); // limpa a tela do lcd
  lcd.setCursor(0, 0); // seta o cursor na coluna 0, linha 0
  lcd.print("distancia: ");
  lcd.setCursor(0, 1);
  lcd.print(distancia); // escreve o a distancia no lcd
  
  delay(1000);
}
#include <LiquidCrystal_I2C.h> // incluindo a biblioteca LCD com módulo I2C
#include <dht.h> // incluindo a biblioteca de sensor de umidade e temperatura do ar

LiquidCrystal_I2C lcd(0x27, 16, 2);  //cria o objeto lcd, 0x27 caracteres, 16 colunas e 2 linhas
const int pinoDHT11 = A2; // define o pino do sensor DHT na porta analógica 2
dht DHT; // cria o objeto sensor de umidade e temperatura do ar

void setup() {

    Serial.begin(9600);
    lcd.init();       // iniciando o lcd
    lcd.backlight();  // ligando o backlight do lcd
}

void loop() {
    DHT.read11(pinoDHT11);             //LÊ AS INFORMAÇÕES DO SENSOR
    Serial.print("Umidade: ");         //IMPRIME O TEXTO NA SERIAL
    Serial.print(DHT.humidity);        //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
    Serial.print("%");                 //ESCREVE O TEXTO EM SEGUIDA
    Serial.print(" / Temperatura: ");  //IMPRIME O TEXTO NA SERIAL
    Serial.print(DHT.temperature, 0);  //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
    Serial.println("*C");              //IMPRIME O TEXTO NA SERIAL
    delay(2000);                       //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR

    lcd.clear();  // limpando a tela do lcd
    lcd.setCursor(0, 0); // coloca o cursor na coluna 0 linha 0
    lcd.print("T: "); // imprime no visor lcd na posição setada acima
    lcd.setCursor(4, 0);
    lcd.print(DHT.temperature, 0);
    lcd.setCursor(0, 1);
    lcd.print("U: ");
    lcd.setCursor(4, 1);
    lcd.print(DHT.humidity);

}
#include <Servo.h> // incluindo a biblioteca do servo
#include <LiquidCrystal_I2C.h> // incluindo a biblioteca de LCD com módulo I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // criando o objeto lcd
Servo servo1, servo2, servo3, servo4; // criando os objetos servos

int XPin = A0; // atribuindo as portas as variáveis dos joysticks
int YPin = A2;
int ZPin = A3;
int WPin = A4;

const int servoMin = 0; // criando o valor minimo dos graus do servo 
const int servoMax = 180; // criando o valor máximo dos graus do servo

// Posição__ vai receber a média do intervalo do servo
int XPosition = (servoMin + servoMax) / 2;
int YPosition = (servoMin + servoMax) / 2;
int ZPosition = (servoMin + servoMax) / 2;
int WPosition = (servoMin + servoMax) / 2;

void setup()
{
  // ligando os servos nas portas digitais correspondentes
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);

  lcd.init(); // iniciando o lcd
  lcd.backlight(); // ligando o backlight do lcd
}

void loop()
{
  // __Valor vai receber um valor entre -5 e 5 para jogar na nova Posição__
  float xVal = (analogRead(XPin) - 512) / 100; // -5 to +5
  // _Posição recebe um valor a ser restringido do intervalo servoMin a ServoMax
  // função constrain(x, a, b) retorna:
  // - x se x estiver entre a e b
  // - a se x for maior que a
  // - b se x for menor que b
  XPosition = constrain(XPosition + xVal, servoMin, servoMax);
  float yVal = (analogRead(YPin) - 512) / 100; // -5 to +5
  YPosition = constrain(YPosition + yVal, servoMin, servoMax);
  float zVal = (analogRead(ZPin) - 512) / 100; // -5 to +5
  ZPosition = constrain(ZPosition + zVal, servoMin, servoMax);
  float wVal = (analogRead(WPin) - 512) / 100; // -5 to +5
  WPosition = constrain(WPosition + wVal, servoMin, servoMax);

  // escreve as posições 
  servo1.write(XPosition);
  servo2.write(YPosition);
  servo3.write(ZPosition);
  servo4.write(WPosition);

  lcd.clear(); // limpando a tela do lcd
  lcd.setCursor(0, 0); // coloca o cursor na coluna 0 linha 0
  lcd.print(XPosition); // escreve na colocação setada acima o valor de XPosition
  lcd.setCursor(6, 0);
  lcd.print(YPosition);
  lcd.setCursor(0, 1);
  lcd.print(ZPosition);
  lcd.setCursor(6, 1);
  lcd.print(WPosition);
}

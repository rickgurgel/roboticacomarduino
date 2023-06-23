# roboticacomarduino
A ideia deste repositório é reunir todos os códigos feitos em sala.

## ControlaServoPorJoystickOuPotenciometro
Utilizando o método map() e potenciômetros ou joystick, conseguimos controlar os servos motores. Com um porém: a posição do joystick não é mantida quando soltamos o mesmo.

* **map()**: esta função recebe os atributos: map(valor, deBaixo, deCima, paraMínimo, paraMáximo). Por interpolação remapeará o *valor* dos intervalos (deBaixo, deCima), para os intervalos (paraMínimo, paraMáximo)
    * valor: valor de entrada
    * deBaixo: menor valor do alcance atual da entrada
    * deCima: maior valor do alcance atual da entrada
    * paraMínimo: valor mínimo alvo do intervalo que transformará o resultado
    * paraMáximo: valor máximo alvo do intervalo que transformará o resultado

## ControlaServoUsandoConstrain
Utilizando o método constrain(), eliminamos o porém de não conseguirmos manter a posição do joystick.
* **constrain()**: esta função recebe os atributos: constrain(x, a, b). Retorna:
    * *x*: se x estiver entre a e b;
    * *a*: se x for maior que a;
    * *b*: se x for menor que b;

## MedidorDeDistanciaUtilizandoUltrassom
Com o sensor HCRS04 (sensor ultrassom) conseguimos medir distâncias.
* Biblioteca utilizada está adicionada aos arquivos.
* **dist()**: este método retorna a distância medida em centímetros.

## MedidorDeTemperaturaEUmidadeDoAr
Utilizando o sensor DHT11 para medir a temperatura e umidade do ar.
* Biblioteca utilzada está adicionada aos arquivos.
* **humidity()**: retorna a umidade medida (%)
* **temperature**: retorna a temperatura, consultar biblioteca para checar atributos.

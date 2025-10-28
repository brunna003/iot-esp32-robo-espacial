# iot-esp32-robo-espacial
Projeto IoT com ESP32 - Controle de Robô Espacial

## Objetivo da Etapa
Nosso objetivo é desenvolver um sistema de controle remoto para robô espacial que utiliza a conexão via WIFI para criar a comunicação entre o esp32 e o joystick criado no WOKWI.

## Componentes do Circuito
- 1 × ESP32
- 1 × Joystick analógico
- 1 × Botão
- 1 × LED Verde
- 1 x LED Vermelho
- 2 × Resistores 220Ω

## Rodar o Joystick no Wookwi
* Primeiro deve-se montar o circuito no WOKWI com base nos materias mostrado anteriormete.
* Depois basta copiar o codigo contido no arquivo sketch.ino e colar na aba de codigos dentro do WOKWI.

## Componentes do robô fisico:
- 1 x ESP32
- 1 x Protoboard
- 2 x Servo motores
- 1 x Sensor de temperatura
- 1 x Fotorrerirtor
- 1 x Sensor de presença (PIR)
- 1 x Led verde
- 1 x Led vermelho

## Como rodar o robô fisico:
*  Copie o codigo que se encontra em robo-lab e coloque para compilar no esp32.


## Como rodar o backend Python:
1 - Baixar o aplicativo SQL

2 - copie e compile o codigo contido em robo-lab banco de dados.

3 - Quando for colocar pra rodar o codigo deve-se colcoar o terminal do vscode:

* 1 - uvicorn main:app --host 0.0.0.0 --port 8000

## Como consultar dados salvos:

1 - Para consultar os dados utilize o site: http://127.0.0.1:8000/leituras


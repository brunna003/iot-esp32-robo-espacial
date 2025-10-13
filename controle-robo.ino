// ANAOGICO -> vertical - 4; Horizontal - 35; Sel - 5
// led vermelho - 12
// led verde - 13
// botão - 34

#define JOY_X 35
#define JOY_Y 4
#define BTN 34
#define LED_GREEN 13
#define LED_RED 12

bool roboLigado = true;
int lastStableState;
int lastReading;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 50ms debounce

unsigned long lastCommandTime = 0;
const unsigned long commandInterval = 300; // 300ms entre comandos joystick

void setup() {
  Serial.begin(115200);

  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  pinMode(BTN, INPUT); // botão com resistor externo pull-down

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  lastStableState = digitalRead(BTN);
  lastReading = lastStableState;

  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);

  Serial.println("Controle remoto inicializado.");
  Serial.println("Robô ligado.");
}

void loop() {
  int xValue = analogRead(JOY_X);
  int yValue = analogRead(JOY_Y);
  int reading = digitalRead(BTN);

  // debounce do botão
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != lastStableState) {
      lastStableState = reading;

      // borda de descida: botão apertado
      if (lastStableState == LOW) {
        roboLigado = !roboLigado;
        if (roboLigado) {
          Serial.println("Comando enviado: LIGAR");
        } else {
          Serial.println("Comando enviado: DESLIGAR");
        }
      }
    }
  }

  lastReading = reading;

  // atualiza LEDs
  if (roboLigado) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);

    // envia comandos joystick a cada 300ms sem bloquear
    if (millis() - lastCommandTime >= commandInterval) {
      if (xValue < 1500) {
        Serial.println("Comando: Direita"); // invertido
      } else if (xValue > 3000) {
        Serial.println("Comando: Esquerda"); // invertido
      } else if (yValue < 1500) {
        Serial.println("Comando: Trás"); // invertido
      } else if (yValue > 3000) {
        Serial.println("Comando: Frente"); // invertido
      } else {
        Serial.println("Comando: Parado");
      }
      lastCommandTime = millis();
    }
  } else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
  }
}

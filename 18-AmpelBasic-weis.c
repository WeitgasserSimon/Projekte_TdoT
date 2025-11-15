#define LED_ROT 11
#define LED_GELB 12
#define LED_GRUEN 13


// mit enum verschiedene (5) zustände anlegen, durch enum kann man ordentliche namen vergeben, intern wird mit 1 2 3 4 5 gearbeitet
// gmecaht für bessere lesbarkeit
enum AmpelState { 
  ROT,
  ROT_GELB,
  GRUEN,
  GRUEN_BLINK,
  GELB
};

AmpelState state = ROT;
unsigned long previousMillis = 0;
unsigned long interval = 0;
int blinkCount = 0;
bool gruenAn = false;

void setup() {
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
  digitalWrite(LED_ROT, HIGH);
  interval = 3000;
}

void loop() {
  unsigned long currentMillis = millis();

  switch (state) {
    case ROT:
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        state = ROT_GELB;
        digitalWrite(LED_GELB, HIGH);
        interval = 1000;
      }
      break;

    case ROT_GELB:
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        state = GRUEN;
        digitalWrite(LED_ROT, LOW);
        digitalWrite(LED_GELB, LOW);
        digitalWrite(LED_GRUEN, HIGH);
        interval = 4000;
      }
      break;

    case GRUEN:
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        state = GRUEN_BLINK;
        blinkCount = 0;
        gruenAn = true;
        interval = 500;
      }
      break;

    case GRUEN_BLINK:
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        gruenAn = !gruenAn;
        digitalWrite(LED_GRUEN, gruenAn ? HIGH : LOW);
        if (!gruenAn) blinkCount++;
        if (blinkCount >= 3) {
          state = GELB;
          digitalWrite(LED_GRUEN, LOW);
          digitalWrite(LED_GELB, HIGH);
          interval = 1000;
          previousMillis = currentMillis;
        }
      }
      break;

    case GELB:
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        state = ROT;
        digitalWrite(LED_GELB, LOW);
        digitalWrite(LED_ROT, HIGH);
        interval = 3000;
      }
      break;
  }
}

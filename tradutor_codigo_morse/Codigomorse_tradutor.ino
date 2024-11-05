#include <Arduino.h>

#define led_13 13
#define btn 10
#define ledPin1 8
#define ledPin2 9
#define buzzer 11
int btnclick = 0;
int btnfree = 0;
int lerBuffer = 0;


void setup() {
  // Inicializa a comunicação serial a 9600 bps
  Serial.begin(9600);
  pinMode (btn, INPUT);
  pinMode (led_13, OUTPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // Espera a abertura do monitor serial
  while (!Serial) {
    ; // Não faz nada até a porta serial estar conectada
  }

  // Mensagem inicial para o usuário
  Serial.println("Digite uma palavra:");
}

void loop() {
  verificaBtn();
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0 and lerBuffer == 1) {
    // Lê a palavra digitada
    String palavra = Serial.readStringUntil('\n');

    // Imprime cada letra separadamente
    for (int i = 0; i < palavra.length(); i++) {
      Serial.println(palavra[i]);
      char character = palavra[i] ; // Lê o caractere do monitor serial
      blinkMorse(character); // Pisca o LED em código Morse
    }

    // Mensagem para o usuário digitar outra palavra
    lerBuffer = 0;
    Serial.println("Digite outra palavra:");
  }
}


void  verificaBtn() {
  if (digitalRead(btn) == HIGH) {
    btnclick = 1;
    btnfree = 0;
    digitalWrite(led_13, HIGH);
  } else {
    btnfree = 1;
    digitalWrite(led_13, LOW);
  }
  if (btnclick == 1 && btnfree == 1) {
    btnclick = 0;
    btnfree = 0;
    lerBuffer = 1;
  }
}

void blinkMorse(char character) {
  String morseCode = getMorseCode(character); // Obtém o código Morse para o caractere
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode[i] == '.') {
      blinkDot(); // Pisca um ponto

    } else if (morseCode[i] == '-') {
      blinkDash(); // Pisca um traço
    }
    delay(300); // Pausa entre os sinais
  }
  delay(1000); // Pausa entre os caracteres
}

String getMorseCode(char character) {
  character = toupper(character);
  switch (character) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}

void blinkDot() {
  digitalWrite(ledPin1, HIGH);
  tone(buzzer, 1000);
  delay(300);
  digitalWrite(ledPin1, LOW);
  noTone(buzzer);
  delay(300);
}

void blinkDash() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  tone(buzzer, 1000);
  delay(1200);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  noTone(buzzer);
  delay(300);
}
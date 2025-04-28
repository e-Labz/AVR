
### Definição de Macros para Debug

O código usa diretivas de pré-processador (#define) para determinar se a depuração (DEBUG) está ativada ou não.

Se DEBUG for igual a 1, são definidas as macros DEBUG_LOG(msg) e LOG(msg), que registram mensagens no monitor serial.

DEBUG_LOG(msg): Exibe o nome do arquivo (__FILE__), a linha do código (__LINE__) e a mensagem fornecida.

LOG(msg): Registra o tempo (millis()), a linha de código e a mensagem.

Caso DEBUG seja 0, as macros são definidas como vazias, impedindo qualquer saída de depuração.

```
#define DEBUG 1

#if DEBUG
  #define DEBUG_LOG(msg) Serial.print("[" __FILE__ ":" + String(__LINE__) + "] " + msg)
  #define LOG(msg) Serial.print("[" + String(millis()) + ":" + __LINE__ + "] " + msg)
#else
  #define DEBUG_LOG(msg)
  #define LOG(msg)
#endif

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  delay(5000);
}

void loop() {
  LOG("Iniciando leitura do sensor\n");
  int sensorValue = analogRead(A0);
  //DEBUG_LOG("Sensor: ");
  DEBUG_LOG("Sensor: " + sensorValue + "\n");
  delay(1000);
}
```


### Macro TASK
A macro TASK(interval, condition) permite a execução de um bloco de código repetidamente a cada interval milissegundos, enquanto condition for verdadeira.

- Utiliza millis() para medir o tempo desde o início do programa, sem bloquear a execução, ao contrário de delay().
- Registra a última execução (lastExecution) e só executa o código novamente se a condição for verdadeira e o tempo do intervalo tiver passado.

```
/* * *
 *  Macro TASK: Executa uma tarefa a cada 'interval'
 *  ms usando millis() se 'condition' for verdadeira.
 *  Use 'true' para tarefas sem condições específicas
 *
 *  Use: TASK(interval, condition) { ..code.. }
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define TASK(interval, condition) \
  for(static unsigned long lastExecution = 0; \
      ({ unsigned long _now = millis(); \
         bool _exec = (condition) && (_now - lastExecution >= (unsigned long)(interval)); \
         if (_exec) lastExecution = _now; \
         _exec; }); \
      ) if (true)

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  delay(5000);
}

void loop() {
  TASK(1000, 1) {  // Task1
    static unsigned count = 0; count++;
    readSensor("Task1", A0, count);
  }

  TASK(1750, 1) {  // Task2
    static unsigned count = 0; count++;
    readSensor("Task2", A1, count);
  }

  TASK(3600, 1) {  // Task3
    static unsigned count = 0; count++;
    readSensor("Task3", A2, count);
  }
}

void readSensor(const char* taskName, int port, long count) {
    int sensor = analogRead(port);
    char logMessage[100]; // Buffer para armazenar a mensagem formatada

    // Formatando a mensagem no buffer
    sprintf(logMessage, "[%ld:%ld] %s port: %d: %d", millis(), count, taskName, port, sensor);

    // Enviando a mensagem ao monitor serial
    Serial.println(logMessage);
}
```

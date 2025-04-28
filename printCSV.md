
Codigo simples para demostrar a leitura das portas analógicas e apresentação em formato CSV via porta serial

- Utiliza bitfileds para armazenar em 10 bits a leitura de cada porta analogica

```
struct Sensor { // 4x 10 bit bitfield
  unsigned int a0 : 10;
  unsigned int a1 : 10;
  unsigned int a2 : 10;
  unsigned int a3 : 10;
} sensor;

void readSensor() {
  sensor.a0 = analogRead(A0); delay(50);
  sensor.a1 = analogRead(A1); delay(50);
  sensor.a2 = analogRead(A2); delay(50);
  sensor.a3 = analogRead(A3); delay(50);
}

void printCSV() {
  Serial.print(sensor.a0);
  Serial.print(",");
  Serial.print(sensor.a1);
  Serial.print(",");
  Serial.print(sensor.a2);
  Serial.print(",");
  Serial.println(sensor.a3); // Último elemento usa println para nova linha
}

void setup() {
  Serial.begin(9600);
  Serial.println("a0,a1,a2,a3"); // Cabeçalho CSV
}

void loop() {
  readSensor();
  printCSV();
  delay(10000); // Executa a cada 10 segundos
}
```

/* 
 *  Definimos la libreria que se va utilizar para que 
 *  la placa de arduino utilice el minimo de consumo 
 *  de energia
 */
#include <LowPower.h>

/*
 * Definimos las variables y constantes los pin utilizados en la placa arduino
 */
const int wakeUpPin = 2;
#define buzzer 11

/*
 * Declaramos el metodo wakeUp para poder hacer uso de
 * la interrupcion
 */
void wakeUp() {

}

/*
 * Definimos los tipos (entrada - salida) de cada 
 * componente utilizado
 */
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(buzzer, OUTPUT);
}

/*
 * 
 */
void loop() {
    sonarAlarma();
  interrupcion();
}

/*
 * Metodo que contiene la interrupcion
 */
 
void interrupcion() {
  attachInterrupt(0, wakeUp, LOW);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0);
}

/*
 * Establecemos la secuencia de sonido del buzzer y
 * el tiempo de parpadeo del led integrado en la placa
 * arduino 
 */
 
void sonarAlarma() {
  digitalWrite(LED_BUILTIN, HIGH);
  analogWrite(buzzer, 190); // Mandamos la señal para hacer sonar el buzzer durante la secuencia de alarma
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  analogWrite(buzzer, 0); // Apagamos la señal de sonido del buzzer
  delay(100);
}

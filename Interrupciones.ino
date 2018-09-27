/* 
 *  Definimos las librerias que se van a utilizar, una para que 
 *  la placa de arduino utilice el minimo de consumo 
 *  de energia y otra para el funcionamiento del teclado respectivamente
 */
 
#include <LowPower.h>
#include <Keypad.h> 

/*
 * Definimos las variables y constantes junto con los pin utilizados en la placa arduino
 */
#define buzzer 11
String clave = "1234";
char iniciaClave = '#'; // Solo al presionar "#" podremos ingresar la clave
char activaAlarma = 'A'; // Solo al presionar "A" podremos activar de nuevo la alarma

/*
 * La variable "flag" nos permite controlar el sonido de la alarma cuando se ingresa una clave 
 * correcta(deja de sonar) o incorrecta(sigue sonando)
 */
 
boolean flag = false;
char claveCorrecta[] = "1234"; // Aquí escribimos la contraseña de 4 dígitos
const int PINWAKEUP = 2; // Pin de la interrupcion
const byte FILAS = 4; //Numero de FILAS del teclado que se esta usando
const byte COLUMNAS = 4; //Numero de COLUMNAS del teclado que se esta usando
char teclas[FILAS][COLUMNAS] =  //Aquí pondremos la disposición de los caracteres tal cual están en nuestro teclado
{
  {'1', '2', '3', 'A'},

  {'4', '5', '6', 'B'},

  {'7', '8', '9', 'C'},

  {'*', '0', '#', 'D'}
};

byte pinFilas[FILAS] = {10, 9, 8, 7}; // Seleccionamos los pines en el arduino donde iran conectadas las filas
byte pinColum[COLUMNAS] = {6, 5, 4, 3}; // Seleccionamos los pines en el arduino donde iran conectadas las columnas

/*
 * Inicializamos el teclado creando una instancia del tipo Keypad llamada Teclado y le
 * asignamos las teclas que se tienen el el array teclas para posteriormente indicarle
 * los numeros de pines que tienen sus filas y columnas
 */
 
Keypad Teclado = Keypad(makeKeymap(teclas), pinFilas, pinColum, FILAS, COLUMNAS);

/*
 * Declaramos el metodo wakeUp para poder hacer uso de
 * la interrupcion
 */
void wakeUp() {

}

/*
 * Definimos los tipos (entrada - salida) de cada 
 * componente utilizado e inicializamos el monitor serie
 */
 
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(buzzer, OUTPUT);
}

/*
 * Mandamos a llamar a los diferentes metodos para que cumplan con sus respectivas funcionalidades
 * interrupcion: Cuando se cierra la puerta (iman en el red switch)
 * sonarAlarma: Seguira activa mientras no se ejecute la interrupcion o la clave ingresada
 * por teclado no sea la correcta
 * validaClave: Verifica si la clave ha sido ingresada correctaente para cambiar el estado de la
 * variable flag y asi poder desactivar la alarma aunque la puerta se encuentre abierta
 */
void loop() {
    interrupcion();
  if (flag == false) {
    sonarAlarma();
  }
  validaClave();
}

/*
 * Metodo que contiene la interrupcion
 * Utilizamos la interrupcion LOW para que se ejecute continuamente mientras este en ese estado
 * El primer parametro es el numero de la interrupcion, el segundo es de la función asociada en el programa
 * y el tercero es el tipo de interrupcion que se esta utilizando
 */
 
void interrupcion() {
  attachInterrupt(0, wakeUp, LOW);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0); // Aquí anulamos la interrupción cuando se cierre la puerta
}

void validaClave() {
  int n = 0;

  char tecla = Teclado.getKey(); // Cuando se pulse una tecla sera guardada en esta variable
  if (tecla != NO_KEY) { // NO_KEY es una constante definida en Keypad.h para identificar el pulso de teclas
    if (activaAlarma == tecla) { // Evalua cuando se pulse la tecla "A" para activar la alarma en caso de que este desactivada
      flag = false; // Ponemos nuestra bandera en falso para que siga sonando la alarma
      Serial.print("Alarma activada");
    } else if (iniciaClave == tecla) { // Evalua cuando se pulsa "#" para evaluar si se ingreso la clave correcta y poder desactivar la alarma
      Serial.println("Ingresa clave");
      while (n < 4) {
        clave[n] = Teclado.waitForKey(); // Aquí guardamos caracter por caracter lo que se ingresa por teclado
        n = n + 1;
      }
      Serial.println(clave);
      
      /*
       *  Si la clave ingresada es correcta nuestra bandera se cambia a true para que asi 
       *  la alarma deje de sonar 
       */
       
      if (clave == claveCorrecta) {
        Serial.println("Clave valida");
        analogWrite(buzzer, 0);
        flag = true;

        /*
         *  En caso contrario la alarma seguira sonando y nuestra variable flag se quedara
         *  en falso para indicar que la clave ha sido incorrecta y la alarma no pudo
         *  ser desactivada
         */
         
      } else {
        Serial.print("Clave no  valida");
        flag = false;
      }
    }
  }
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

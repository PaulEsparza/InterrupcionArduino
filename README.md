*Version 1.2 - 27 - Sep - 2018*

# Practica 2. Interrupciones y Bajo Consumo Energetico En Arduino

Esta practica consiste en `simular una alarma con arduino para el acceso a una puerta`, cuyo funcionamiento es que cuando la puerta este abierta, una alarma debe de sonar en caso contrario deberia de mantenerse en silencio.
Como `funcionalidad adicional` se implemento un `teclado matricial` para poder mantener la puerta abierta ingresando una clave y poder activar de nuevo la alarma a traves de otra clave para asi poder reanudar el funcionamiento normal del programa.

Tabla De Contenido
--------------------

- [Requisitos](#requisitos).
- [Materiales](#materiales).
- [Contenido Del Proyecto](#contenido-del-proyecto).
- [Instrucciones Para Importar Las Bibliotecas utilizadas](#importar-librerias).
- [Tecnologías Usadas](#tecnologias-usadas).
- [Autor](#autor).
- [Requisitos](#requisitos).
- [Requisitos](#requisitos).
- [Requisitos](#requisitos).
- [Requisitos](#requisitos).

Requisitos
-----------

- [x] Mientras la alarma no este sonando el arduino debera `consumir la mínima cantidad de energía`.
- [x] Mientras la puerta este abierta, l`a alarma debera de sonar` alertando a la persona de dicho caso.
- [x] Cuando la puerta se cierre `la alarma dejara de sonar` y regresar al estado de bajo consumo energético. 


Materiales
-----------

   * Protoboard
    
   * Placa arduino
    
   * Cables
    
   * 1 Red Switch
    
   * 1 Imán
    
   * 1 Teclado Matricial
    
   * 1 Buzzer


Contenido Del Proyecto
-----------------------

   * Biblioteca LowPower.h: Gestiona el modo sleep de arduino para que pueda consumir el minimo de recursos de energía al ejecutar una interrupción. 

   * Biblioteca Keypad.h: Es una biblioteca que nos permite usar teclados de matriz de estilo con el Arduino. 
    
   * Carpeta De Imágenes: Esta carpeta muestra de manera gráfica la implemetacion de la práctica.

   * Programa En El IDE Arduino : Script con la solucion del problema planteado.
    
   * README.md : Este archivo.

Instrucciones Para Importar Las Bibliotecas utilizadas
--------------------------------------------------------

> Paso 1:
>> Seleccionamos el menú "Programa".
> Paso 2:
>> Seleccionamos el sub-menú "Incluir librería".
> Paso 3:
>> Seleccionamos la opción "Añadir librería .ZIP".
> Paso 4:
>> Buscamos y seleccionamos las librerías de este proyecto para que sean añadidas y puedan ser utilizadas por el programa.
> Paso 5:
>> Por ultimo añadimos las líneas siguientes dentro de la ventana del programa y así no tener problemas al momento de ejecutar nuestro proyecto:
>> #include <LowPower.h>
>> #include <Keypad.h>
    

Tecnologías Usadas
-------------------

* La aplicación está estructurada utilizando :

   * Sistema Operativo `Ubuntu 16.04 LTS`.
    
   * `IDE Arduino`.
    
Autor
------

*Paul Esparza*

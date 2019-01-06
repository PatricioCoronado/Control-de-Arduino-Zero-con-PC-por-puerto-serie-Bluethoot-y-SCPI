/*
	Patricio Coronado
	Proyecto:Pruebas con un módulo bluetooth HC-06  
	Fichero:Prueba_HC-06.ino
	27 de Noviembre de 2017  
	Revisado el 29 de Mayo de 2018
*/
#include <Arduino.h>
#include "Prueba_HC-06_SCPI.h"// Menú SCPI del proyecto
// Variables del sistema
/*
1 set to 1200bps
2 set to 2400bps
3 set to 4800bps
4 set to 9600bps (Default)
5 set to 19200bps
6 set to 38400bps
7 set to 57600bps
8 set to 115200bps
Enviando AT+BAUD4 pone el baudrate a 9600.
Instalación en Windows 10
En Windows 10, se agrega el dispositivo bluetooth con el pin 4321. El PC instala 2 puertos COM. El módulo bluetooth comunica con el primero;
si son COM42 y COM43, comunica con el COM42. Con el programa Terminal B@yBray no funciona. Con Putty si, poniendo el protocolo a NONE.

*/
//char VelocidadBT='4';//9600 Si es la primera vez que conecta el HC-06 hay que poner esta linea y no la siguiente
char VelocidadBT='8';//115200
char NombreBT[8]="BT_PCC1";//Nombre del módulo bluetooth
//char pin[5]="1234"; //Pin anterior del módulo bluetooth
char Pin[5]="4321"; //Pin del módulo bluetooth
//
void setup()
{
  NOMBRE_DEL_SISTEMA_64B(Pruebas bluetooth con HC-06)
  pinMode(LED_BUILTIN,OUTPUT);

// La configuración del módulo se hace una sola vez. En el proceso hay que flasearlo 2 veces con el código de
// configuración habilitado. Una vez configurado se puede quitar el código de configuración
/* 
// Inicio configuración del módulo bluetooth..........................................................................  
// Puerto hardware Serial1, con las salidas por el pin 0 y 1.
// La primera vez se flasea el micro con:
// Serial1.begin(9600);
// Se configura el módulo con las siguientes lineas y finalmente se reabre el puerto con Serial1.begin(115200).
// Ahora se flasea otra ver con esta linea a Serial1.begin(115200) y el módulo queda a 115200
  Serial1.begin(115200); 
  // Configuración del dispositivo HC-06
  Serial1.print("AT");
  delay(1000);
  //Cambia el nombre del módulo
  Serial1.print("AT+NAME");
  Serial1.print(NombreBT);
  delay(1000);
  //Cambia el pin del módulo
  Serial1.print("AT+PIN");
  Serial1.print(Pin);
  delay(1000);
  // Cambia el baudrate del módulo
  Serial1.print("AT+BAUD");
  Serial1.print(VelocidadBT);
  delay(1000);
//Fin configuración del módulo bluetooth..............................................................................
*/
  // Abre el puerto serie con el mismo baudrate del módulo
  Serial1.begin(115200);
  delay(200);
}
void loop()
{
	if (Serial1.available()){/*delay(100);Espera a que el buffer se llene*/scpi();}
}
/*****************************************************************
	Comando COMANDO1 ó C1
	Ejecuta la función void fs1(void);
*****************************************************************/
void fs1(void)
{
	Serial1.println
	("Se ha recibido el COMANDO1 y se ha ejecutado la funcion fs1");
}
/*****************************************************************
	Comando COMANDO2 ó C2
	Ejecuta la función void fs1(void);
*****************************************************************/
void fs2(void)
{
	Serial1.println
	("Se ha recibido el COMANDO2 y se ha ejecutado la funcion fs2");
}
/****************************************************************
	Comando SUBMENU1:COMANDO11 ó SM1:C11
	Ejecuta la función void fs3(void);
	Cambia el valor de la variable tipo double "Variable1"
*****************************************************************/
void fs3(void)
{
	static double Variable1=1.1;
	int Resultado;
	Resultado=cambia_variable_double_del_sistema(&Variable1,10.0,0.0);
	switch (Resultado)
	{
		case 0:
			Serial1.println("No Se cambio el valor de la Variable1");
			errorscpi(7);
		break;
		case 1:
			Serial1.println("Se cambio el valor de la Variable1");
		break;
		case 2:
			Serial1.println("Se envio al PC el valor de la Variable1");
		break;
	}
}
/*****************************************************************
	Comando SUBMENU1:COMANDO11 ó SM1:C12
	Ejecuta la función void fs4(void);
	Cambia el valor de la variable tipo int "Variable2"
*****************************************************************/
void fs4(void)
{
	int Resultado;
	static int Variable2=100;
	int ValoresVariable2[]={1,10,100};
	Resultado=cambia_variable_int_discreta_del_sistema(&Variable2,ValoresVariable2,sizeof(ValoresVariable2));
	switch (Resultado)
	{
		case 0:
			Serial1.println("No Se cambio el valor de la Variable2");
		errorscpi(7);
		break;
		case 1:
			Serial1.println("Se cambio el valor de la Variable2");
		break;
		case 2:
			Serial1.println("Se envio al PC el valor de la Variable2");
		break;
	}	
}

/************************************/ /*FIN********************************************/
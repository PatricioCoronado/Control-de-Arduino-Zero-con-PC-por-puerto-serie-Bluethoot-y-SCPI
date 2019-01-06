// Test_Segainvex_SCPI_Serial
// Ejemplo de uso de la librería Segainvex_SCPI para comunicar un PC con Arduino a través del
// puerto serie que soporta Serial, Serial1 y SerialUSB
//
#include <Arduino.h>
#include <segainvex_scpi_Serial.h> // funciones y variables de Segainvex_SCPI

 tipoNivel SUBMENU1[] = //Array de estructuras tipo Nivel
{
	SCPI_COMANDO(COMANDO11,C11,fs3)//Comando que ejecuta la función fs3()
	SCPI_COMANDO(COMANDO12,C12,fs4)//Comando que ejecuta la función fs4()
	// TO DO Añadir aquí comandos o submenús
};
 tipoNivel NivelDos[] = //Array de estructuras tipo Nivel
{
SCPI_SUBMENU(SUBMENU1,SM1 )	
	SCPI_COMANDO(COMANDO1,C1,fs1) //Comando que ejecuta la función fs1()
	SCPI_COMANDO(COMANDO2,C2,fs2) //Comando que ejecuta la función fs2()
	SCPI_COMANDO(ERROR,ERR,fs243)// Envía el ultimo error
	SCPI_COMANDO(*IDN,*IDN,fs240)// Identifica el instrumento
	SCPI_COMANDO(*OPC,*OPC,fs248)// Devuelve un 1 al PC
	SCPI_COMANDO(*CLS,*CLS,fs255)// Borra la pila de errores
};
SCPI_NIVEL_RAIZ// Macro que hace la declaración obligatoria del nivel Raiz
tipoCodigoError CodigoError=
{
  " ",						// ERROR N. 0
  "1 Caracter no valido",                // ERROR N. 1
  "2 Comando desconocido",               // ERROR N. 2
  "3 Cadena demasiado larga",            // ERROR N. 3
  "4 Parametro inexistente",             // ERROR N. 4
  "5 Formato de parametro no valido",    // ERROR N. 5
  "6 Parametro fuera de rango",          // ERROR N. 6
  // Errores personalizados por el usuario 
  "7 El dato no esta listo",		// ERROR N. 7
};	


void setup() 
{

//Macro de Segainvex_SCPI que rellena una cadena con el nombre del sistema
//NOMBRE_DEL_SISTEMA_64B(Prueba de Segainvex_SCPI para Arduino V1.0)
// Abre el puerto serie
SerialUSB.begin(115200); 
}
void loop()
{
  // Si recibe algo por el puerto serie lo procesa con SEGAINVEX_SCPI 
  if (SerialUSB.available()){scpi();}
	  //delay(1000);
/*
TO DO Poner aquí el código de usuario
*/
}// loop() 

//Ahora solo nos queda definir las funciones de nuestro sistema:

void fs1(void)
{
 SerialUSB.println
 ("Se ha recibido el COMANDO1 y se ha ejecutado la funcion fs1");	
}
void fs2(void)
{
 SerialUSB.println
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
			SerialUSB.println("No Se cambio el valor de la Variable1");
			errorscpi(7);
		break;
		case 1:
			SerialUSB.println("Se cambio el valor de la Variable1");
		break;
		case 2:
			SerialUSB.println("Se envio al PC el valor de la Variable1");
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
			SerialUSB.println("No Se cambio el valor de la Variable2");
		errorscpi(7);
		break;
		case 1:
			SerialUSB.println("Se cambio el valor de la Variable2");
		break;
		case 2:
			SerialUSB.println("Se envio al PC el valor de la Variable2");
		break;
	}	
}


/************************************/ /*FIN********************************************/
 

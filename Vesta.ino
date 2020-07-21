
#include <SPI.h>
#include <HardwareSerial.h>
#include <vestaConfig.h>
#include <vestaLib.h>
//#include "pruebas.h"
#include "parking.h"

//pruebas myModule = pruebas(); //Placa prototipo
parking myModule = parking(); //Placa del parking de la comunidad

void setup()
{
	Serial.begin(9600);		
  	myModule.vSetup(); 
}
void loop()
{
  	myModule.vLoop();
}

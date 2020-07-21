#include <vestaLib.h>
//Installed devices includes
#include <VestaDHT.h>
#include <VestaInput.h>
#include <VestaOutput.h>
#include <VestaGate.h>

#ifndef montefaroParking_h
#define montefaroParking_h

class parking: public vestaLib
{
  public:
    parking();
    void devicesSetup(); //Inicio de los dispositivos

  private:
    //Instanciation
    VestaDHT dh0 = VestaDHT();
    
    vestaInput puertaAbierta = vestaInput();
    vestaInput puertaCerrada = vestaInput();

    vestaInput fotocelula = vestaInput();
    vestaInput detectorCorriente = vestaInput();

    vestaOutput releAbre = vestaOutput();
    vestaOutput releCierra = vestaOutput();

    vestaGate puerta = vestaGate();


};
#endif

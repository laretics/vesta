  #include "parking.h"
  #include <vestaConfigItem.h> 
  #include <vestaConfig.h>

  parking::parking():vestaLib(){mainController=this;}
  void parking::devicesSetup()
  {
    vestaLib::devicesSetup(); //Llamada al padre
    vestaConfigItem *mainModuleConfig = &config.CommonHeader;

    mainModuleConfig->pData->roBlock.buzzerPin=39; //Salida del sonido
    mainModuleConfig->pData->roBlock.TCPLedPin=7; //Pool Domus


    unsigned char idPuertaAbierta,idPuertaCerrada,idFotocelula,idDetectorCorriente,idReleAbre,idReleCierra;

    VestaDHTConfig *dhconf;
    dhconf=(VestaDHTConfig*)dh0.getConfigItem();
    dhconf->setPins(4,5,3);

    vestaInputConfig *pentrada;
    pentrada = (vestaInputConfig*)puertaAbierta.getConfigItem();
    pentrada->setPins(40);
    pentrada = (vestaInputConfig*)puertaCerrada.getConfigItem();
    pentrada->setPins(41);
    pentrada = (vestaInputConfig*)fotocelula.getConfigItem();
    pentrada->setPins(42);
    pentrada = (vestaInputConfig*)detectorCorriente.getConfigItem();
    pentrada->setPins(43);

    vestaOutputConfig *psalida;
    psalida = (vestaOutputConfig*)releAbre.getConfigItem();
    psalida->setPins(27);
    psalida = (vestaOutputConfig*)releCierra.getConfigItem();
    psalida->setPins(28);

    config.installDevice(&dh0);

    idPuertaAbierta = config.installDevice(&puertaAbierta);
    idPuertaCerrada = config.installDevice(&puertaCerrada);
    idFotocelula = config.installDevice(&fotocelula);
    idDetectorCorriente=config.installDevice(&detectorCorriente);
    
    idReleAbre=config.installDevice(&releAbre);
    idReleCierra=config.installDevice(&releCierra);

    vestaGateConfig *pgate;
    pgate = (vestaGateConfig*)puerta.getConfigItem();
    
    pgate->setInputs(idPuertaAbierta,idPuertaCerrada,idFotocelula,idDetectorCorriente);
    pgate->setOutputs(idReleAbre,idReleCierra);
    config.installDevice(&puerta);
      

    Serial.println("Loaded devices");
  }

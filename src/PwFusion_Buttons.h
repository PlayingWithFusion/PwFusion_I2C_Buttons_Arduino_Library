// Buttons.h

#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"
#include <PwFusion_Data_Transfer.h>

class Buttons {

  private:
    uint8_t _adr;
    DataTransfer* transfer;

    uint8_t reg_BTN = 0x00;
    int _numData = 1;

  public:
    Buttons(/*uint8_t adr*/);
    int getBtn();
    void begin(uint8_t adr);

};

#endif
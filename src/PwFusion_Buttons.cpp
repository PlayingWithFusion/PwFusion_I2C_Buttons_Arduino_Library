// Buttons.cpp

#include "PwFusion_Buttons.h"
#include "Arduino.h"
#include <PwFusion_Data_Transfer.h>



Buttons::Buttons(/*uint8_t adr*/) {
  // _adr = adr;

  // transfer = new DataTransfer(_adr, _numData);

}

void Buttons::begin(uint8_t adr) {
  _adr = adr;

  transfer = new DataTransfer(/*_adr, _numData*/);
  transfer->begin(_adr, _numData);
}

int Buttons::getBtn() {
  return transfer->getData(reg_BTN);
}

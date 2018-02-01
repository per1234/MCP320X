#include <Arduino.h>
#include <SPI.h>
#include "MCP320X.h"

#define START 1

uint16_t inputConfiguration = 0;
uint16_t CS;
uint16_t nbChannel = 0;
bool mcpSet = 0;

int16_t mcp320xRead(uint8_t channel) {
  int16_t ans = 0;
  if (mcpSet) {
    if (channel <= nbChannel) {
      uint8_t SEND1 = 0x00 | (START << 2) | (inputConfiguration << 1) | (channel >> 2);
      uint16_t SEND2 = 0x00 | (channel << 14);
      digitalWrite(CS, LOW);
      SPI.transfer(SEND1);
      uint16_t value = SPI.transfer16(SEND2) & 0x0FFF;
      digitalWrite(CS, HIGH);
      ans = value;
    }else{
      ans = -1;
    }
  }
  return ans;
}


void mcp320xSet(uint16_t inputConf, uint16_t mcpType, uint16_t slavePin) {
  if (inputConfiguration <= 1) {
    inputConfiguration = inputConf;
  } else {
    inputConfiguration = 0;
  }
  CS = slavePin;
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  nbChannel = mcpType - 1;
  mcpSet = 1;
}

# MCP320X
Arduino library for MCP3204 and MCP3208

List of Function

mcp320xSet(uint16_t inputConf, uint16_t mcpType, uint16_t slavePin);
  inputConf : chose if you want Single-ended or differential value 
  You have to chose between SINGLE and DIFF
  mcpType : chose the device you use, chose MCP3204 or MCP3208.
  slavePin : chose your SPI CS pin

int16_t mcp320xRead(uint8_t channel);
channel : chose the channel for the MCP to read the 12bit analogic value

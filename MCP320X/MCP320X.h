#ifndef MCP320X_H
#define MCP320X_H

#define SINGLE 1
#define DIFF 0

#define MCP3204 4
#define MCP3208 8

int16_t mcp320xRead(uint8_t channel);
void mcp320xSet(uint16_t inputConf, uint16_t mcpType, uint16_t slavePin);


#endif

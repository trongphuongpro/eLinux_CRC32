#include <stdint.h>

typedef uint32_t crc32_t;

#define CRC32POLY	0x04C11DB7
#define CRC32POLYREVERSE    0xEDB88320
#define LEN     (8*sizeof(CRC32_t))
#define MSB     (1 << (LEN-1))

uint8_t reflect(uint8_t);
crc32_t calcCRC32(const char*);
void createCRC32Table();

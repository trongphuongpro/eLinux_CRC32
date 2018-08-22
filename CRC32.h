#include <stdint.h>

typedef uint32_t CRC32;

#define crc32poly	0x04C11DB7
#define crc32polyreverse    0xEDB88320
#define LEN     (8*sizeof(CRC32))
#define MSB     (1 << (LEN-1))

uint8_t reflect(uint8_t);
CRC32 calcCRC32(const char*);
void createCRC32Table();
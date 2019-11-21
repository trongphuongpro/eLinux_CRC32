#include <stdint.h>

#define CRC32POLY			0x04C11DB7
#define CRC32POLYREVERSE	0xEDB88320
#define LEN					(8*sizeof(CRC32_t))
#define MSB					(1 << (LEN-1))

typedef uint32_t crc32_t;
uint8_t reflect(uint8_t);
crc32_t crc32_compute(const char*);
void crc32_init();

#include "CRC32.h"

CRC32 crc32Table[256];

uint8_t reflect(uint8_t number) {
	uint8_t result = 0;
	for (uint8_t i = 0; i < 8; i++) {
		result = (result << 1) + ((number >> i) & 1);
	}
	return result;
}

void createCRC32Table() {
    CRC32 remainder;
    for (int data = 0; data < 256; data++) {
        remainder = data;
        for (uint8_t bit = 0; bit < 8; bit++) {
            if (remainder & 1)
                remainder = (remainder >> 1) ^ crc32poly;
            else
                remainder >>= 1;
        }
        crc32Table[data] = remainder;
    }
}

CRC32 calcCRC32(const char *msg) {
    CRC32 remainder = 0xFFFFFFFF;
    uint8_t data;
    
    for (uint8_t i = 0; msg[i] != '\0'; i++) {
        remainder = crc32Table[(remainder & 0xFF) ^ msg[i]] ^ (remainder >> 8);
    }
    remainder ^= 0xFFFFFFFF;
	
    return remainder;
}
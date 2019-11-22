#include <stdio.h>
#include "crc32.h"


int main() {
	crc32_init();
	uint8_t data[9] = {'1','2','3','4','5','6','7','8','9'};

	crc32_t crc = crc32_compute(data, sizeof(data));
	printf("CRC32: %#x\n", crc);
	printf("Check: %d\n", crc32_check(data, sizeof(data), crc));
}
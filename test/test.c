#include <stdio.h>
#include "crc32.h"


int main() {
	crc32_init();
	uint8_t data[1] = {0};

	crc32_t crc = crc32_compute(data, sizeof(data));
	printf("CRC32: %#x\n", crc);
	printf("Check: %d\n", crc32_check(data, sizeof(data), crc));
}
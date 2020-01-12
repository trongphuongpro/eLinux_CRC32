#include <stdio.h>
#include <string.h>
#include "crc32.h"


int main() {
	char *data[] = {"codelungtung.com", "trongphuongpro"};

	crc32_t crc = crc32_concat(crc32_compute(data[0], strlen(data[0])), data[1], strlen(data[1]));

	printf("CRC32: %#x\n", crc);
}
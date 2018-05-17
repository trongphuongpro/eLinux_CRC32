  //////////////////////////////////////////////////
 // CRC-32 Calculator for Single ASCII Character //
//////////////////////////////////////////////////
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define CRC32	0x104C11DB7

uint8_t reflect(uint8_t);
uint32_t calcCRC32(uint8_t);

int main(int argc, char **argv) {
	
	if (argc > 1)
		calcCRC32(argv[1][0]);
		
	return 0;
}

uint8_t reflect(uint8_t number) {
	uint8_t result = 0;
	for (uint8_t i = 0; i < 8; i++) {
		result = (result << 1) + ((number >> i) & 1);
	}
	return result;
}

uint32_t calcCRC32(uint8_t number) {
	uint8_t reflected = reflect(number);
	uint64_t reminder = ((uint64_t)reflected << 32) ^ ((uint64_t)0xFFFFFFFF << 8);
	uint8_t polyLength = (uint8_t)ceil(log(CRC32)/log(2));
	uint8_t reminderLenght = (uint8_t)ceil(log(reminder)/log(2));
	
	printf("CRC-32 Poly: %#llx\n", CRC32);

	//printf("Length of CRC-32: %d\n", polyLength);
	//printf("Number: %#x\n", number);
	//printf("Reflected: %#x\n", reflected);

	while (reminderLenght > polyLength-1) {
		//printf("Reminder: %#x", reminder >> 32);
		//printf("%08x\n", reminder & 0xFFFFFFFF);
		//printf("Length of reminder: %d\n", reminderLenght);
		reminder ^= CRC32 << (reminderLenght-polyLength);
		reminderLenght = (uint8_t)ceil(log(reminder)/log(2));
	}
	//printf("Reminder: %#x", reminder >> 32);
	//printf("%08x\n", reminder & 0xFFFFFFFF);
	//printf("Length of reminder: %d\n", reminderLenght);
	
	reminder ^= 0xFFFFFFFF;
	//printf("Reminder: %#x\n", reminder);
	
	reminder = (reflect(reminder & 0xFF) << 24) | (reflect((reminder >> 8) & 0xFF) << 16) | (reflect((reminder >> 16) & 0xFF) << 8) | (reflect((reminder >> 24) & 0xFF));
	printf("Result: %#010X\n", reminder);
}
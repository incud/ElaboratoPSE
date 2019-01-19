#ifndef XTEA_H_
#define XTEA_H_

#include <stdint.h>

void xtea (
	uint32_t word0, uint32_t word1,
	uint32_t key0,  uint32_t key1,
	uint32_t key2,  uint32_t key3,
	bool mode,
	uint32_t * result0, uint32_t * result1);

#endif

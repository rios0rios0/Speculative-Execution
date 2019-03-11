//
// Created by rios0rios0 on 08/03/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _MSC_VER
#include <intrin.h>        /* for rdtscp and clflush */
#pragma optimize("gt",on)
#else
#include <x86intrin.h>     /* for rdtscp and clflush */

#endif
#define CACHE_L1_ALL_SIZE (32) //32K, by the Yarom2015MappingTI
#define CACHE_L1_LINE_SIZE (64) //64B, by the Yarom2015MappingTI
#define CACHE_L1_LINES ((CACHE_L1_ALL_SIZE * 1024) / CACHE_L1_LINE_SIZE)
#define CACHE_L2_ALL_SIZE (256) //256K
#define CACHE_L3_ALL_SIZE (4096) //256K
//With bash command:
//      lscpu | grep cache
//      getconf -a | grep CACHE

#define CACHE_HIT_THRESHOLD (80)  /* assume cache hit if time <= threshold */
//uint8_t = 1 Byte, then:
uint8_t cache_l1[CACHE_L1_ALL_SIZE * 1024];

int main(int argc, const char **argv) {
	uint8_t array[10 * 4096];
	int junk = 0;
	register uint64_t time1, time2;
	volatile uint8_t *addr;
	int i;
	//Initialize the array
	for (i = 0; i < 10; i++) array[i * 4096] = 1;
	//FLUSH the array from the CPU cache
	//for (i = 0; i < 10; i++) _mm_clflush(&array[i * 4096]);

	long tmp1 = 727007342310;
	long tmp2 = 281474976710655;
	printf("tmp1 ==> %p\n", (void *) tmp1);
	printf("tmp2 ==> %p\n", (void *) tmp2);
	//__builtin___clear_cache((void *) tmp1, (void *) tmp2);
	__clear_cache((void *) tmp1, (void *) tmp2);

	//Access some of the array items
	array[3 * 4096] = 100;
	array[7 * 4096] = 200;
	for (i = 0; i < 10; i++) {
		addr = &array[i * 4096];
		time1 = __rdtscp(&junk);
		junk = *addr;
		time2 = __rdtscp(&junk) - time1;
		printf("Access time for array[%d*4096]: %d CPU cycles\n", i, (int) time2);
	}
	return 0;
}
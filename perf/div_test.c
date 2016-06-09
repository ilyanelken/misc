#include <stdio.h>
#include <inttypes.h>
#include <time.h>

static const int iters = 1024 * 1024 * 1024;

/*
 * Note:
 *
 *      Converting signed to float is faster than converting unsigned
 *
 */

int main(int argc, char **argv)
{
	clock_t begin, end;
	double time_delta;
	int ret;
	uint64_t x = 0xDEADBEAF;
	long int y = 0xDEADBEAF;
	unsigned i;

	begin = clock();
	for (i = 0; i < iters; i++) {
        ret = y / (i + 1);
	}
	end = clock();
	time_delta = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Signed division test:\t%.2lf [msec]\n", time_delta * 1000);

	begin = clock();
	for (i = 0; i < iters; i++) {
        ret = x / (i + 1);
	}
	end = clock();
	time_delta = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Unsigned division test:\t%.2lf [msec]\n", time_delta * 1000);

	return 0;
}

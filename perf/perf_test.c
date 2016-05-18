#include <stdio.h>
#include <time.h>

static const int iters = 1024 * 1024 * 16;

int max(int a, int b)
{
	return a > b ? a : b;
}


int main(int argc, char **argv)
{
	clock_t begin, end;
	double time_delta;
	int ret;
	int x = 10;
	int y = 20;
	unsigned i;

	begin = clock();
	for (i = 0; i < iters; i++) {
		ret = max(x, y);
	}
	end = clock();
	time_delta = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Regular test:\t%.2lf [msec]\n", time_delta * 1000);

	begin = clock();
	for (i = iters; i != 0; i -= 8) {
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
		ret = max(x, y);
	}
	end = clock();
	time_delta = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Improved loop test:\t%.2lf [msec]\n", time_delta * 1000);

	return 0;
}

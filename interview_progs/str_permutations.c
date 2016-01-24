#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_perm(char *str, int left, int right)
{
	char tmp;
	int i, j;

	if (left == right) {
		printf("%s\n", str);
		return;
	}

	for (i = left; i <= right; i++) {
		swap(str + left, str + i);
		print_perm(str, left + 1, right);
		swap(str + left, str + i);
	}
}

int main(int argc, char **argv)
{
	char str_arr[] = "abc";
	char *str = str_arr;

	if (argv[1])
		str = argv[1];

	print_perm(str, 0, strlen(str) - 1);

	return 0;
}

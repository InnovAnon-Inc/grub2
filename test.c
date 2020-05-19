#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double freq(unsigned int bf, unsigned int n[12], unsigned int d[12], size_t i) { return (double) bf * n[i] / d[i]; }
unsigned int uifreq(unsigned int bf, unsigned int n[12], unsigned int d[12], size_t i) { return (unsigned int) (freq(bf, n, d, i) + .5); }

int main() {
	unsigned int tempo = 60 * 4;
	unsigned int bf    = 432;

	unsigned int n[] = {1, 15, 8, 6, 5, 4, 7, 10, 3, 8, 5, 7, 15};
	unsigned int d[] = {1, 14, 7, 5, 4, 3, 5,  7, 2, 5, 3, 4,  8};
	// A4
	//unsigned int n[] = {1, 15, 8, 6, 5, 4, 7, 3, 8, 5, 7, 15};
	//unsigned int d[] = {1, 14, 7, 5, 4, 3, 5, 2, 5, 3, 4,  8};
	// d5
	//unsigned int n[] = {1, 15, 8, 6, 5, 4, 10, 3, 8, 5, 7, 15};
	//unsigned int d[] = {1, 14, 7, 5, 4, 3,  7, 2, 5, 3, 4,  8};

	//ssize_t      tune[] = {4, 0, 4, 8, 12, 11, 9, -1,   7, 3, 12, 11, 6, 4, 3, -1,   4, 0, 4, 8, 12, 11, 9, -1,    6, 4, 11, 10, 8, 6, 5};
	//unsigned int dura[] = {3, 1, 2, 2,  3,  3, 5,  1,   3, 1,  2,  2, 3, 3, 5,  1,   3, 1, 2, 2,  3,  3, 5,  1,    3, 1,  2,  2, 3, 3, 6};

	//ssize_t      tune[] = {4, 0, 4, 8, 12, 11, 9, -1,
	//                       6, 7, 13, 12, 8, 6, 5, -1,
	//                       4, 0, 4, 8, 12, 11, 9, -1,
	//                       7, 3, 12, 11, 6, 4, 3, -1};
	ssize_t      tune[] = {4, 0, 4, 8, 12, 11, 9, -1,
	                       7, 4, 13, 12, 6, 3, 2, -1,
	                       4, 0, 4, 8, 12, 11, 9, -1,
	                       7, 3, 12, 11, 6, 4, 3, -1};
	unsigned int dura[] = {3, 1, 2, 2,  3,  3, 5,  1,
	                       3, 1,  2,  2, 3, 3, 5,  1,
	                       3, 1, 2, 2,  3,  3, 5,  1,
	                       3, 1,  2,  2, 3, 3, 5,  1};

	printf("%u\n", tempo);

	size_t i;
	for (i=0; i < sizeof(tune) / sizeof(tune[0]); i++) {
		if (tune[i] == -1) {
			printf("0 %u\n", dura[i]);
			continue;
		}
		size_t       j   = (size_t) tune[i] % (sizeof(n) / sizeof(n[0]));
		unsigned int oct = (size_t) tune[i] / (sizeof(n) / sizeof(n[0]));
		printf("%u %u\n", (1 + oct) * uifreq(bf, n, d, j), dura[i]);
	}

	return EXIT_SUCCESS;
}

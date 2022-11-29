#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, n, a = 1, b = 2, c;
	scanf("%d", &n);
	if (n == 1)
		printf("1");
	else if (n == 2)
		printf("2");
	else {
		for (i = 2; i < n; i++) {
			c = b;
			b = (b + a) % 10007;
			a = c;
		}

		printf("%d", b);
	}

	return EXIT_SUCCESS;
}
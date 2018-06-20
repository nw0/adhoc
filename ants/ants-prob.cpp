/* Two ants on a line move left or right 7 times each.
 * They start 10 units apart.
 * What are the chances that they meet?
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>

int move() {
	return rand() % 2 ? 1 : -1;
}

int meet() {
	int lpos = -5;
	int rpos = 5;
	
	for (int i=0; i<7; i++) {
		lpos += move();
		rpos += move();
		if (lpos == rpos)
			return 1;
	}
	return 0;
}

int main() {
	int N = 1000000;
	int meetings = 0;

	srand(time(NULL));

	for (int i=0; i<N; i++)
		meetings += meet();
	
	float chance = 1. * meetings / N;
	printf("%f\n", chance);
}

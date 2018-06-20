#include <cstdio>

static int tcc[8];

char interp(int i) {
	switch (i) {
		case 0: return 'L';
		case 1: return 'T';
		case 2: return 'A';
		case 3: return 'L';
	}
	return 'X';
}

int lx (int i) {
	return i % 2 ? 1 : -1;
}

int rx (int i) {
	return i / 2 ? 1 : -1;
}

int win(int path) {
	int tc = 0;
	int p = path;
	int cc[256] = {0};

	for (int i=0; i<7; i++) {
		int sit = p % 4;
		cc[interp(sit)]++;
		p /= 4;
	}
	if (cc['T'] == 5) {
		if (cc['A'] == 2) tcc[5]++;
		else if (cc['L'] == 2) tcc[6]++;
		else tcc[7]++;
	}
	return 1;
}

int meet(int path, int li, int ri) {
	int lpos = li, rpos = ri;
	int p = path;
	
	for (int i=0; i<7; i++) {
		int sit = p % 4;

		lpos += lx(sit);
		rpos += rx(sit);
		
		if (lpos == rpos)
			return win(path);

		p /= 4;
	}
	return 0;
}

int main() {
	int meetings = 0;
	int N = 16384;

	for (int i=0; i<N; i++) {
		meetings += meet(i, -5, 5);
	}

	printf("%d meetings\n", meetings);
	printf("t5: %d, t6: %d, t7: %d\n", tcc[5], tcc[6], tcc[7]);
}

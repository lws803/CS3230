#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>

inline int getint(){
	char c;
	while ((c = getchar_unlocked()) <= ' ');
	int v = 0;
	do { v = (v << 3) + (v << 1) + (c ^ '0'); }
	while ((c = getchar_unlocked()) >= '0' && c <= '9');
	return v;
}

int main(){
	int v, e, t;
	v = getint();
	e = getint();
	t = getint();

	// input edges and process answer

	int answer = 0;
	printf("%d\n", answer);
	return 0;
}

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>
#include <vector>

// fast way to read next integer
inline int getint(){
	char c;
	while ((c = getchar_unlocked()) <= ' ');
	int v = 0;
	do { v = (v << 3) + (v << 1) + (c ^ '0'); }
	while ((c = getchar_unlocked()) >= '0' && c <= '9');
	return v;
}
std::vector<int> stack_boxes(int N, int S, std::vector<int>& W) {
    std::vector<int> final_stack(N);
    for (int i = 0; i < N; ++i) {
        // modify this logic
        final_stack[i] = i + 1;
    }
    return final_stack;
}
int main(){
    int N = getint();
    int S = getint();
    std::vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        W[i] = getint();
    }
    int index = 0;
    std::vector<int> answer = stack_boxes(N, S, W);
    for (int i : answer) {
        printf("%d%c", i, ++index < answer.size() ? ' ' : '\n');
    }
	return 0;
}

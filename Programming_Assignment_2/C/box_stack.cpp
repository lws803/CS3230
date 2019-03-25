#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

#define MAX 2147483646

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>
#include <vector>

using namespace std;


// fast way to read next integer
inline int getint(){
    char c;
    while ((c = getchar_unlocked()) <= ' ');
    int v = 0;
    do { v = (v << 3) + (v << 1) + (c ^ '0'); }
    while ((c = getchar_unlocked()) >= '0' && c <= '9');
    return v;
}
std::vector<int> stack_boxes(int N, int S, std::vector<int>& W, int max_index) {
    vector<vector<int>> K(N+1, vector<int> (S+1, 0));
//    memset(K, 0, sizeof K);
//    for (int i = 0; i <= N; i++) {
//        for (int d = 0; d <= S; d++) {
//            K[i][d] = 0;
//        }
//    }
    vector<int> final_stack;
    
//    vector<int> predecessor[N+1][S+1];
    
    W[max_index] = MAX;
    
    // modified knapsack problem??
    for (int i = 0; i <= N; ++i) {
        for (int d = 0; d <= S; d++) {
            if (i == 0 || d == 0) {
                K[i][d] = 0;
            } else if (W[i-1] <= d) {
                if (W[i-1]+K[i-1][d-W[i-1]] > K[i-1][d]) {
                    K[i][d] = W[i-1] + K[i-1][d-W[i-1]];
//                    predecessor[i][d] = predecessor[i-1][d-W[i-1]];
//                    //                    predecessor[i][d].push_back(W[i-1]);
//                    predecessor[i][d].push_back(i-1);
                } else {
                    K[i][d] = K[i-1][d];
//                    predecessor[i][d] = predecessor[i-1][d];
                }
            } else {
                K[i][d] = K[i-1][d];
//                predecessor[i][d] = predecessor[i-1][d];
            }
        }
    }
    int res = K[N][S];
    int w = S;
    for (int i = N; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            final_stack.push_back(i-1);
            res = res - W[i - 1];
            w = w - W[i - 1];
        }
    }
    final_stack.push_back(max_index);

//    cout << K[N][S] << endl;
//    predecessor[N][S].push_back(max_index);
    return final_stack;
}


int main(){
    int N = getint();
    int S = getint();
    std::vector<int> W(N);
    int my_index = 0;
    int maximum = W[my_index];
    for (int i = 0; i < N; ++i) {
        W[i] = getint();
        if (W[i] > maximum) {
            maximum = W[i];
            my_index = i;
        }
    }
//    sort(W.begin(), W.end());
    int index = 0;
    std::vector<int> answer = stack_boxes(N, S, W, my_index);
    for (int i : answer) {
        printf("%d%c", i+1, ++index < answer.size() ? ' ' : '\n');
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

int a9663[21];
int b9663[21];
int N9663, M9663;
int ans9663 = 0;
int s9663[21] = {};
bool find9663 = false;
bool check9663(int k) {
    for (int j = 0; j < k; j++) {
        if (b9663[j] == b9663[k] || abs(b9663[k] - b9663[j]) == k - j) {
            return false;
        }
    }
    return true;
}
void dfs9663(int k) {
    if (k == N9663) {
        ans9663++;
    }
    else {
        for (int i = 0; i < N9663; i++) {
            b9663[k] = i;
            if (check9663(k)) {
                dfs9663(k + 1);
            }
        }
    }
}

void n9663() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N9663;
    dfs9663(0);
    printf("%d", ans9663);

}

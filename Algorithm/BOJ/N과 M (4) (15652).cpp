#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int arr4[10];
bool visited4[10];
int N4, M4;

void dfs4(int num, int k) {
    if (k == M4) {
        for (int i = 0; i < M4; i++) {
            cout << arr4[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i <= N4;i++) {
            arr4[k] = i;
            dfs4(i, k + 1);
        }
    }
}

void n15652() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N4 >> M4;
    dfs4(1, 0);
}

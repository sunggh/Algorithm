#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int arr3[10];
bool visited3[10];
int N3, M3;

void dfs3(int k) {
    if (k == M3) {
        for (int i = 0; i < M3; i++) {
            cout << arr3[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N3;i++) {
            arr3[k] = i;
            dfs3(k + 1);
        }
    }
}

void n15651() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N3 >> M3;
    dfs3(0);
}

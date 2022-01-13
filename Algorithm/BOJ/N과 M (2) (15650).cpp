#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int arr2[10];
bool visited2[10];
int N2, M2;

void dfs2(int num2, int k) {
    if (k == M2) {
        for (int i = 0; i < M2; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num2; i <= N2;i++) {
            arr2[k] = i;
            dfs2(i + 1, k + 1);

        }
    }
}

void n15650_() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N2 >> M2;
    dfs2(1, 0);
}

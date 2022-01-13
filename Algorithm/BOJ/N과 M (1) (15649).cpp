#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int arr1[10];
bool visited[10];
int N1, M1;

void dfs1(int k1) {
    if (k1 == M1) {
        for (int i = 0; i < M1; i++) {
            cout << arr1[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N1;i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr1[k1] = i;
                dfs1(k1 + 1);
                visited[i] = false;
            }
        }
    }
}

void n15649() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N1 >> M1;
    dfs1(0);
}

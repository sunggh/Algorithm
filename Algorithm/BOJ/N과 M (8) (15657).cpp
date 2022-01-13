#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> arr8;
int arr8_[10];
bool visited8[10];
int N8, M8;

void dfs8(int num, int k) {
    if (k == M8) {
        for (int i = 0; i < M8; i++) {
            cout << arr8_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i < N8;i++) {
            arr8_[k] = arr8[i];
            dfs8(i, k + 1);
        }
    }
}

void n15657() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N8 >> M8;
    for (int i = 0; i < N8;i++) {
        int x;
        cin >> x;
        arr8.push_back(x);
    }
    sort(arr8.begin(), arr8.end());
    dfs8(0, 0);
}

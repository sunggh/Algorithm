#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> arr6;
int arr6_[10];
bool visited6[10];
int N6, M6;

void dfs6(int num, int k) {
    if (k == M6) {
        for (int i = 0; i < M6; i++) {
            cout << arr6_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i < N6;i++) {
            arr6_[k] = arr6[i];
            dfs6(i + 1, k + 1);
        }
    }
}

void n15655() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N6 >> M6;
    for (int i = 0; i < N6;i++) {
        int x;
        cin >> x;
        arr6.push_back(x);
    }
    sort(arr6.begin(), arr6.end());
    dfs6(0, 0);
}

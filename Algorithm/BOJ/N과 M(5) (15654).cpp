#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> arr5;
int arr5_[10];
bool visited5[10];
int N5, M5;

void dfs5(int k) {
    if (k == M5) {
        for (int i = 0; i < M5; i++) {
            cout << arr5_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N5;i++) {
            if (!visited5[i]) {
                visited5[i] = true;
                arr5_[k] = arr5[i - 1];
                dfs5(k + 1);
                visited5[i] = false;
            }
        }
    }
}

void n15654() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N5 >> M5;
    for (int i = 0; i < N5;i++) {
        int x;
        cin >> x;
        arr5.push_back(x);
    }
    sort(arr5.begin(), arr5.end());
    dfs5(0);
}

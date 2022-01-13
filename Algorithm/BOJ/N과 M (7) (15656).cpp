#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> arr7;
int arr7_[10];
bool visited7[10];
int N7, M7;

void dfs7(int k) {
    if (k == M7) {
        for (int i = 0; i < M7; i++) {
            cout << arr7_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < N7;i++) {
            arr7_[k] = arr7[i];
            dfs7(k + 1);
        }
    }
}

void n15656() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N7 >> M7;
    for (int i = 0; i < N7;i++) {
        int x;
        cin >> x;
        arr7.push_back(x);
    }
    sort(arr7.begin(), arr7.end());
    dfs7(0);
}

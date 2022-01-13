#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

vector<int> arr10;
int arr10_[10];
bool visited10[10];
int N10, M10;
map<int, int> s10;

void dfs10(int num, int k) {
    if (k == M10) {
        for (int i = 0; i < M10; i++) {
            cout << arr10_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i < N10;i++) {
            if (s10[arr10[i]] > 0) {
                s10[arr10[i]]--;
                arr10_[k] = arr10[i];
                dfs10(i, k + 1);
                s10[arr10[i]]++;
            }

        }

    }
}

void n15664() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N10 >> M10;
    int N = N10;
    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        if (s10[x] > 0) {
            s10[x]++;
            N10--;
        }
        else {
            arr10.push_back(x);
            s10[x] = 1;
        }


    }
    sort(arr10.begin(), arr10.end());
    dfs10(0, 0);
}

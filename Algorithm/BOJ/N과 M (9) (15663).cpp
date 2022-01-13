#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

vector<int> arr9;
int arr9_[10];
bool visited9[10];
int N9, M9;
map<int, int> s9;

void dfs9(int k) {
    if (k == M9) {
        for (int i = 0; i < M9; i++) {
            cout << arr9_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < N9;i++) {
            if (s9[arr9[i]] > 0) {
                s9[arr9[i]]--;
                arr9_[k] = arr9[i];
                dfs9(k + 1);
                s9[arr9[i]]++;
            }

        }

    }
}

void n15663() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N9 >> M9;
    int N = N9;
    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        if (s9[x] > 0) {
            s9[x]++;
            N9--;
        }
        else {
            arr9.push_back(x);
            s9[x] = 1;
        }


    }
    sort(arr9.begin(), arr9.end());
    dfs9(0);
}

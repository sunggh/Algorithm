#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

vector<int> arr11;
int arr11_[11];
bool visited11[11];
int N11, M11;
map<int, int> s11;

void dfs11(int num, int k) {
    if (k == M11) {
        for (int i = 0; i < M11; i++) {
            cout << arr11_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < N11;i++) {
            arr11_[k] = arr11[i];
            dfs11(i, k + 1);

        }

    }
}

void n15665() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N11 >> M11;
    int N = N11;
    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        if (s11[x] > 0) {
            s11[x]++;
            N11--;
        }
        else {
            arr11.push_back(x);
            s11[x] = 1;
        }


    }
    sort(arr11.begin(), arr11.end());
    dfs11(0, 0);
}

#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

vector<int> arr12;
int arr12_[12];
bool visited12[12];
int N12, M12;
map<int, int> s12;

void dfs12(int num, int k) {
    if (k == M12) {
        for (int i = 0; i < M12; i++) {
            cout << arr12_[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i < N12;i++) {
            arr12_[k] = arr12[i];
            dfs12(i, k + 1);

        }

    }
}

void n15666() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N12 >> M12;
    int N = N12;
    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        if (s12[x] > 0) {
            s12[x]++;
            N12--;
        }
        else {
            arr12.push_back(x);
            s12[x] = 1;
        }


    }
    sort(arr12.begin(), arr12.end());
    dfs12(0, 0);
}

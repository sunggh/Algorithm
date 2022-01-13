#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

int a6603[15], p6603[15];
int N6603;

void dfs6603(int num, int k) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) {
            cout << p6603[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = num; i < N6603; i++) {
            p6603[k] = a6603[i];
            dfs6603(i + 1, k + 1);
        }
    }
}

void n6603() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> N6603;
        if (N6603 == 0) break;
        for (int i = 0; i < N6603;i++) {
            cin >> a6603[i];
        }
        dfs6603(0, 0);
        cout << "\n";
    }


}

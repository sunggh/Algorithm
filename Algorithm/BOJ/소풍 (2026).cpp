#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

int A2026[101];
int p2026[4];
int N2026, K2026, F2026;
bool f2026[903][903];
vector<int> G2026;

int max2026 = -1000000000, min2026 = 1000000000;

void dfs2026(int num) {
    if (G2026.size() == N2026) {
        for (int i = 0;i < G2026.size(); i++) {
            cout << G2026[i] << "\n";
        }
        exit(0);
    }
    else {
        for (int i = num; i <= K2026; i++) {
            if (G2026.size() == 0)
                G2026.push_back(i);
            else {
                bool check = true;
                for (int j = 0;j < G2026.size();j++) {
                    if (i == G2026[j]) continue;
                    if (!f2026[i][G2026[j]]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    G2026.push_back(i);
                    dfs2026(i + 1);
                    if (G2026.size() > 0)
                        G2026.pop_back();
                }

            }

        }
    }

}

void n2026() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N2026 >> K2026 >> F2026;
    for (int i = 0; i < F2026;i++) {
        int a, b;
        cin >> a >> b;
        f2026[a][b] = true;
        f2026[b][a] = true;
    }
    for (int i = 1;i < K2026;i++) {
        G2026.clear();
        dfs2026(i);
    }

    cout << "-1";
}

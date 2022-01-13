#include <iostream>
#include <queue>
#include <set>
using namespace std;

void n11660()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N >> M;
    vector<vector<int>>a(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
        }
    }


    for (int i = 0; i < M; i++) {
        int s1, s2, e1, e2;
        cin >> s1 >> e1 >> s2 >> e2;
        cout << a[s2][e2] - a[s2][e1 - 1] - a[s1 - 1][e2] + a[s1 - 1][e1 - 1] << "\n";
    }
}

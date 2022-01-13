#include <iostream>
#include <queue>
using namespace std;

void n11659()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N >> M;
    vector<int> a(N);
    cin >> a[0];
    for (int i = 1; i < N;i++) {
        int x = 0;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    for (int i = 0;i < M;i++) {
        int s, e;
        cin >> s >> e;
        if (s - 1 == 0) {
            cout << a[e - 1] << "\n";
        }
        else {
            cout << a[e - 1] - a[s - 1 - 1] << "\n";
        }
    }
}

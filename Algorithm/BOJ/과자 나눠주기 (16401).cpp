#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


void n16401() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, ans = 0;
    vector<int> a;
    int r = 0, l = 1, mid;
    cin >> N >> M;
    for (int i = 0; i < M;i++) {
        int s;
        cin >> s;
        a.push_back(s);
        if (r < s) r = s;
    }

    while (l <= r) {
        mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < a.size();i++) {
            cnt += a[i] / mid;
        }

        if (cnt < N) {
            r = mid - 1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }

    cout << ans;
}

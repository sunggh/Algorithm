#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n1477() {
    int N, M, L;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> L;

    int l, r;
    int  mid;
    vector<int> a;
    for (int i = 0; i < N;i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    a.push_back(0);
    a.push_back(L);
    sort(a.begin(), a.end());
    l = 1;
    r = L - 1;
    while (l <= r) {
        mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i < a.size();i++) {
            cnt += (a[i] - a[i - 1]) / mid;
            if ((a[i] - a[i - 1]) % mid == 0)
                cnt--;
        }
        if (cnt > M) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }


    }
    cout << l;
}

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n2792() {
    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    long long l, r;
    long long mid;
    long long answer = 0;
    vector<long long> a;
    for (int i = 0; i < M;i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    l = 1;
    r = 1000000000;
    int max = 1000000000;
    while (l <= r) {
        mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 0; i < M;i++) {
            cnt += a[i] / mid;
            if (a[i] % mid != 0)
                cnt++;
        }
        if (cnt > N) {
            l = mid + 1;
        }
        else {
            if (max > mid) max = mid;
            r = mid - 1;

        }


    }
    cout << max;
}

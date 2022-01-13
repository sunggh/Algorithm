#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n2805() {
    int N, M, max = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<long long> A;

    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        A.push_back(x);
        if (max < x) max = x;
    }
    int l = 0, r = max, mid;
    long long ans = 0, result=0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ans = 0;
        for (int i = 0; i < N;i++) {
            if (A[i] - mid > 0) {
                ans += (A[i] - mid);
            }
        }
        if (ans >= M) {
            result = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }
    cout << result;

}
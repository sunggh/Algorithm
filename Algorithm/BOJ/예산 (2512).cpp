// study_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n2512() {
    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> A;
    long long sum = 0, max = 0;
    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        A.push_back(x);
        sum += x;
        if (max < x) max = x;
    }


    cin >> M;
    /*if (sum <= M) {
        cout << max;
        return 0;
    }*/
    int l = 1, r = max, mid;
    int ans = 0;

    while (l <= r) {
        mid = (l + r) / 2;
        long long w = 0;
        for (int i = 0; i < N;i++) {
            if (A[i] <= mid)
                w += A[i];
            else
                w += mid;
        }
        if (w <= M) {
            ans = l;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;

}

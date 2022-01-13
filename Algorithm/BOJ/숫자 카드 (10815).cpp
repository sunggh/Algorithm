#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n10815() {
    int N, M, max = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N;i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());

    cin >> M;
    for (int i = 0; i < M;i++) {
        int x;
        cin >> x;
        int l = 0, r = A.size() - 1, mid;
        bool flag = false;
        while (l <= r) {
            mid = (l + r) / 2;

            if (A[mid] == x) {
                flag = true;
                break;
            }

            if (A[mid] < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (flag)
            cout << "1 ";
        else
            cout << "0 ";
    }

}
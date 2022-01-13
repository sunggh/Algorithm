
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n10816() {
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
        cout << upper_bound(A.begin(), A.end(), x) - lower_bound(A.begin(), A.end(), x) << " ";
    }
}
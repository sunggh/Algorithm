// study_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void n1920() {
    int N, M;
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
        int l = 0, r = A.size() - 1;
        int mid;
        bool find = false;
        while (l <= r) {
            mid = (l + r) / 2;
            if (A[mid] == x) {
                find = true;
                break;
            }
            else {
                if (A[mid] > x) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        if (find) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}

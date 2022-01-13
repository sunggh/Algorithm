// study_cpp.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

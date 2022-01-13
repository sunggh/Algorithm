// study_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

void n2417() {
    long long N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;


    long long l = 0, r = sqrt(N), mid;
    long long ans, a;

    while (l <= r) {
        mid = (l + r) / 2;
        a = sqrt(N);
        if (a < mid) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (mid * mid == N)
        cout << mid;
    else
        cout << l;
}

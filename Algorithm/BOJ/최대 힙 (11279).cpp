// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

void n11279()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    int x;
    priority_queue<int> pq;
    cin >> N;
    for (int i = 0;i < N;i++) {
        cin >> x;
        if (x == 0) {
            if (pq.size() != 0) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else {
                cout << "0" << "\n";
            }
        }
        else {
            pq.push(x);
        }
    }
}

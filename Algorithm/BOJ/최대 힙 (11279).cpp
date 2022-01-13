// Algorithm.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

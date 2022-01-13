#include <iostream>
#include <queue>
#include <set>
using namespace std;

void n2075()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    int x;
    priority_queue <int, vector<int>, greater<int>> minpq;

    cin >> N;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> x;
            if (minpq.size() < N) {
                minpq.push(x);
            }
            else {
                if (x > minpq.top()) {
                    minpq.pop();
                    minpq.push(x);
                }
            }
        }
    }
    cout << minpq.top() << "\n";
}

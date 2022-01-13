#include <iostream>
#include <queue>
using namespace std;

void n2696()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0, M;
    int x;
    vector<int> answer;
    priority_queue<int, vector<int>> maxpq; // 작은쪽 
    priority_queue <int, vector<int>, greater<int>> minpq; // 큰쪽

    cin >> T;
    for (int i = 0;i < T;i++) {
        cin >> M;
        for (int j = 0;j < M;j++) {
            cin >> x;
            if (maxpq.size() == minpq.size()) {
                if (maxpq.size() == 0) // 작은쪽이 0일때
                    maxpq.push(x); // 작은쪽에 푸쉬
                else { // 사이즈가 0이 아니면
                    if (x <= minpq.top()) { // x랑 큰쪽 탑 비교 ( x가 큰쪽보다 작을때)
                        maxpq.push(x); // 작은쪽에 x값 넣어주기
                    }
                    else {
                        int temp = minpq.top(); // 큰쪽 값 꺼내서 
                        minpq.pop();
                        maxpq.push(temp); // 작은쪽에 넣어주기
                        minpq.push(x); // 큰쪽엔 x 넣어주기
                    }
                }
            }
            else {
                if (maxpq.size() > minpq.size()) { // 작은쪽이 큰쪽보다 많으면 
                    if (maxpq.top() <= x) { // x가 작은쪽의 탑보다 크거나 같으면 
                        minpq.push(x); //큰쪽에다 넣기
                    }
                    else {
                        int temp = maxpq.top(); // 작은쪽 값 빼기  
                        maxpq.pop();
                        minpq.push(temp);
                        maxpq.push(x);
                    }
                }
            }
            if (j % 2 == 0)
                answer.push_back(maxpq.top());
        }
        cout << answer.size() << "\n";
        for (int j = 0; j < answer.size();j++) {
            cout << answer[j] << " ";
        }
        cout << "\n";
        answer.clear();
        maxpq = priority_queue<int, vector<int>>();
        minpq = priority_queue <int, vector<int>, greater<int>>();
    }
}

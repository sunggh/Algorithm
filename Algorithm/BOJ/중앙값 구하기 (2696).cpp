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
    priority_queue<int, vector<int>> maxpq; // ������ 
    priority_queue <int, vector<int>, greater<int>> minpq; // ū��

    cin >> T;
    for (int i = 0;i < T;i++) {
        cin >> M;
        for (int j = 0;j < M;j++) {
            cin >> x;
            if (maxpq.size() == minpq.size()) {
                if (maxpq.size() == 0) // �������� 0�϶�
                    maxpq.push(x); // �����ʿ� Ǫ��
                else { // ����� 0�� �ƴϸ�
                    if (x <= minpq.top()) { // x�� ū�� ž �� ( x�� ū�ʺ��� ������)
                        maxpq.push(x); // �����ʿ� x�� �־��ֱ�
                    }
                    else {
                        int temp = minpq.top(); // ū�� �� ������ 
                        minpq.pop();
                        maxpq.push(temp); // �����ʿ� �־��ֱ�
                        minpq.push(x); // ū�ʿ� x �־��ֱ�
                    }
                }
            }
            else {
                if (maxpq.size() > minpq.size()) { // �������� ū�ʺ��� ������ 
                    if (maxpq.top() <= x) { // x�� �������� ž���� ũ�ų� ������ 
                        minpq.push(x); //ū�ʿ��� �ֱ�
                    }
                    else {
                        int temp = maxpq.top(); // ������ �� ����  
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

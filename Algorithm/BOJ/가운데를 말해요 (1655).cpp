#include <iostream>
#include <queue>
using namespace std;

void n1655()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    int x;
    priority_queue <int, vector<int>> maxpq; // ������ 
    priority_queue <int, vector<int>, greater<int>> minpq; // ū��

    cin >> N;
    for (int i = 0;i < N;i++) {
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
        printf("%d\n", maxpq.top());
    }
}

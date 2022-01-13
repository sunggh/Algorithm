#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> aa(N+1);
    vector<long long> tree(N + 1);
    for (int i = 1;i <= N;i++) {
        cin >> aa[i];
        int j = i;
        while (j<=N) {
            tree[j] += aa[i];
            j += (j & -j);
        }
    }

    for (int i = 0;i < M + K;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            int j = b;
            int x = c - aa[b];
            aa[b] = c;
            while (j <= N) {
                tree[j] += x;
                j += (j & -j);
            }
        }
        else {
            int bresult = 0 , cresult=0;
            //b 에서 c 까지니깐 c까지 누적합 - b까지 누적합
            b = b - 1;
            while (c > 0) {
                cresult += tree[c];
                c -= (c & -c);
            }
            while (b > 0) {
                bresult += tree[b];
                b -= (b & -b);
            }
            cout << cresult - bresult << "\n";
        }
    }


}

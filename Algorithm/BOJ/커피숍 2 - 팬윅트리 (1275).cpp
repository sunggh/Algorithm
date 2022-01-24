#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;



void n1275_()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M;
    cin >> N >> M;
    vector<long long> a(N + 1);
    vector<long long> tree(N + 1);
    for (int i = 1; i < N + 1;i++) {
        int x;
        cin >> x;
        a[i] = x;
        int j = i;
        while (j <= N) {
            tree[j] += a[i];
            j += (j & -j);
        }
    }

    for (int i = 0; i < M;i++) {
        int x, y, aa, b;
        cin >> x >> y >> aa >> b;
        if (x > y) swap(x, y);
        long long bresult = 0, cresult = 0;
        //b 에서 c 까지니깐 c까지 누적합 - b까지 누적합
        x = x - 1;
        while (y > 0) {
            cresult += tree[y];
            y -= (y & -y);
        }
        while (x > 0) {
            bresult += tree[x];
            x -= (x & -x);
        }
        cout << cresult - bresult << "\n";

        long long j = aa;
        long long diff = b - a[aa];
        a[aa] = b;
        while (j <= N) {
            tree[j] += diff;
            j += (j & -j);
        }
    }
}

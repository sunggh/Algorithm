#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int N13397, M13397;
int l13397 = 0, r13397 = 0;
int  mid13397 = 0, ans13397 = 0;
vector<int> a13397;

bool check13397(int mid) {
    int cnt = 1;
    int min = a13397[0];
    int max = a13397[0];
    for (int i = 1;i < N13397; i++) {
        if (min > a13397[i]) min = a13397[i];
        if (max < a13397[i]) max = a13397[i];

        if (max - min > mid) {
            cnt++;
            max = min = a13397[i];
        }

    }
    return M13397 >= cnt;
}


void n13397() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N13397 >> M13397;
    for (int i = 0; i < N13397;i++) {
        int s;
        cin >> s;
        a13397.push_back(s);
        if (r13397 < s) r13397 = s;
    }

    while (l13397 <= r13397) {
        mid13397 = (l13397 + r13397) / 2;

        if (check13397(mid13397)) {
            ans13397 = mid13397;
            r13397 = mid13397 - 1;
        }
        else {

            l13397 = mid13397 + 1;
        }

    }
    cout << ans13397;
}

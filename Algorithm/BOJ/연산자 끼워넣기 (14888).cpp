#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

int A14888[101];
int p14888[4];
int N14888, M14888;
map<int, int> s14888;

int max14888 = -1000000000, min14888 = 1000000000;

void dfs14888(int num, int k) {
    if (k == N14888 - 1) {
        max14888 = max(max14888, num);
        min14888 = min(min14888, num);
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (p14888[i] > 0) {
                p14888[i]--;
                switch (i)
                {
                case 0:
                    dfs14888(num + A14888[k + 1], k + 1);
                    break;
                case 1:
                    dfs14888(num - A14888[k + 1], k + 1);
                    break;
                case 2:
                    dfs14888(num * A14888[k + 1], k + 1);
                    break;
                case 3:
                    dfs14888(num / A14888[k + 1], k + 1);
                    break;
                }
                p14888[i]++;
            }

        }
    }

}

void n14888() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N14888;
    for (int i = 0; i < N14888;i++) {
        cin >> A14888[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> p14888[i];
    }
    dfs14888(A14888[0], 0);
    printf("%d\n", max14888);
    printf("%d", min14888);

}

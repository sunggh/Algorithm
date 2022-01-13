#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

int a1182[21];
int N1182, M1182;
int ans1182 = 0;
bool find1182 = false;
void dfs1182(int k, int num) {
    if (k == M1182 && num != 0) {
        ans1182++;
    }
    if (num == N1182) return;
    for (int i = num; i < N1182; i++) {
        dfs1182(k + a1182[i], i + 1);
    }
}

void n1182() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N1182 >> M1182;
    for (int i = 0;i < N1182;i++) {
        cin >> a1182[i];
    }
    dfs1182(0, 0);
    printf("%d", ans1182);

}

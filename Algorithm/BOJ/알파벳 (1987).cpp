#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<string>
using namespace std;

int b1987[20][20];
bool a1987[26];
int dx1987[4] = { 1,0,-1,0 };
int dy1987[4] = { 0,-1,0,1 };
int ans1987 = 0;
int R1987, C1987;
void dfs1987(int x, int y, int k) {
    if (ans1987 < k) ans1987 = k;
    a1987[b1987[x][y]] = true;
    for (int i = 0;i < 4;i++) {
        int wx = x + dx1987[i];
        int wy = y + dy1987[i];
        if (wx >= 0 && wx < R1987 && wy >= 0 && wy < C1987) {
            if (a1987[b1987[wx][wy]])
                continue;
            else
            {
                dfs1987(wx, wy, k + 1);
                a1987[b1987[wx][wy]] = false;
            }
        }
    }
}



void n1987() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> R1987 >> C1987;

    for (int i = 0; i < R1987; i++) {
        cin >> s;
        for (int j = 0; j < C1987;j++) {
            b1987[i][j] = s[j] - 'A';
        }
    }
    dfs1987(0, 0, 0);
    cout << ans1987 + 1;
}

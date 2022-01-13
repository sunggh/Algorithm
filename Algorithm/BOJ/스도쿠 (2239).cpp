#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<string>
using namespace std;

int b2239[9][9];
bool row2239[9][10];
bool col2239[9][10];
bool box2239[9][10];
void dfs2239(int k) {
    if (k == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9;j++) {
                cout << b2239[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    else {

        int x = k / 9, y = k % 9;
        if (b2239[x][y] != 0) {
            dfs2239(k + 1);
        }
        else {
            for (int j = 1; j < 10; j++) {
                if (!row2239[x][j] && !col2239[y][j] && !box2239[(x / 3) * 3 + y / 3][j]) {
                    row2239[x][j] = true;
                    col2239[y][j] = true;
                    box2239[(x / 3) * 3 + y / 3][j] = true;
                    b2239[x][y] = j;
                    dfs2239(k + 1);

                    b2239[x][y] = 0;
                    row2239[x][j] = false;
                    col2239[y][j] = false;
                    box2239[(x / 3) * 3 + y / 3][j] = false;
                }
            }
        }



    }
}



void n2239() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9;j++) {
            b2239[i][j] = s[j] - '0';
            if (b2239[i][j] != 0) {
                col2239[j][b2239[i][j]] = true;
                row2239[i][b2239[i][j]] = true;
                box2239[(i / 3) * 3 + j / 3][b2239[i][j]] = true;
            }
        }
    }
    dfs2239(0);

}

#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

int b2580[9][9];
bool row2580[9][10];
bool col2580[9][10];
bool box2580[9][10];
void dfs2580(int k) {
    if (k == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9;j++) {
                cout << b2580[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    else {

        int x = k / 9, y = k % 9;
        if (b2580[x][y] != 0) {
            dfs2580(k + 1);
        }
        else {
            for (int j = 1; j < 10; j++) {
                if (!row2580[x][j] && !col2580[y][j] && !box2580[(x / 3) * 3 + y / 3][j]) {
                    row2580[x][j] = true;
                    col2580[y][j] = true;
                    box2580[(x / 3) * 3 + y / 3][j] = true;
                    b2580[x][y] = j;
                    dfs2580(k + 1);

                    b2580[x][y] = 0;
                    row2580[x][j] = false;
                    col2580[y][j] = false;
                    box2580[(x / 3) * 3 + y / 3][j] = false;
                }
            }
        }



    }
}



void n2580() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9;j++) {
            cin >> b2580[i][j];
            if (b2580[i][j] != 0) {
                col2580[j][b2580[i][j]] = true;
                row2580[i][b2580[i][j]] = true;
                box2580[(i / 3) * 3 + j / 3][b2580[i][j]] = true;
            }
        }
    }
    dfs2580(0);

}

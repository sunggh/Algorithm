#include <iostream>
#include<stack>
#include <vector>
using namespace std;

int N18290, M18290, K18290;
int map18290[10][10];
int ans18290 = -2000000000;
bool visited18290[10][10];

void dfs18290(int num, int k) {
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    if (k == K18290) {
        if (ans18290 < num) {
            ans18290 = num;

        }
    }
    else {


        for (int i = 0;i < N18290;i++) {
            for (int j = 0;j < M18290;j++) {
                if (visited18290[i][j]) continue;
                bool check = false;
                for (int z = 0; z < 4;z++) {
                    int wx = i + dx[z];
                    int wy = j + dy[z];
                    if (0 <= wx && wx < N18290 && 0 <= wy && wy < M18290) {
                        if (visited18290[wx][wy])
                            check = true;
                    }
                }
                if (!check) {
                    visited18290[i][j] = true;
                    dfs18290(num + map18290[i][j], k + 1);
                    visited18290[i][j] = false;
                }

            }
        }
    }
}


void n18290() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N18290 >> M18290 >> K18290;
    for (int i = 0;i < N18290;i++) {
        for (int j = 0; j < M18290; j++) {
            cin >> map18290[i][j];
        }
    }
    dfs18290(0, 0);
    cout << ans18290;
}

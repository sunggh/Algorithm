#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


int depth11437[100002];
map<int, vector<int>> Graph11437;
int parent11437[100002];
bool c11437[100002];
void dfs11437(int index, int depth) {
    c11437[index] = true;
    depth11437[index] = depth;
    for (int j : Graph11437[index]) {
        if (c11437[j]) continue;
        parent11437[j] = index;
        dfs11437(j, depth + 1);
    }
}

int find(int a, int b) {
    int c = a;
    int d = b;
    while (depth11437[c] != depth11437[d]) {
        if (depth11437[c] > depth11437[d]) {
            c = parent11437[c];
        }
        else {
            d = parent11437[d];
        }
    }

    while (c != d) {
        c = parent11437[c];
        d = parent11437[d];
    }
    return c;
}

void n11437()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;

    for (int i = 0; i < N - 1;i++) {
        int a, b;
        cin >> a >> b;
        Graph11437[a].push_back(b);
        Graph11437[b].push_back(a);
    }
    dfs11437(1, 0);
    cin >> M;

    for (int i = 0; i < M;i++) {
        int a, b;
        cin >> a >> b;
        printf("%d\n", find(a, b));
    }
}

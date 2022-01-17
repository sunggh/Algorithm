#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


int depth1761[50002];
map<int, vector<int>> Graph1761;
int parent1761[50002];
bool c1761[50002];
long long sum1761 = 0;
map <pair<int, int>, int> w1761;
void dfs1761(int index ,int depth) {
    c1761[index] = true;
    depth1761[index] = depth;
    for (int j : Graph1761[index]) {
        if (c1761[j]) continue;
        parent1761[j] = index;
        dfs1761(j, depth + 1);
    }
}

int find1761(int a, int b) {
    int c = a;
    int d = b;
    while (depth1761[c] != depth1761[d]) {
        if (depth1761[c] > depth1761[d]) {
            sum1761 += w1761[{c, parent1761[c]}];
            c = parent1761[c];
            
        }
        else {
            sum1761 += w1761[{d, parent1761[d]}];
            d = parent1761[d];
        }
    }

    while (c != d) {
        sum1761 += w1761[{c, parent1761[c]}];
        sum1761 += w1761[{d, parent1761[d]}];

        c = parent1761[c];
        d = parent1761[d];
    }
    return sum1761;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    
    cin >> N;
    for (int j = 0; j < N - 1;j++) {
        int a, b, w;
        cin >> a >> b>>w;
        Graph1761[a].push_back(b);
        Graph1761[b].push_back(a);
        w1761[{a, b}] = w;
        w1761[{b, a}] = w;
    }

    dfs1761(1, 0);
    cin >> M;
    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;
        sum1761 = 0;
        printf("%d\n", find1761(a, b));
    }
}

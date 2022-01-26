#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;


long long init2268(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init2268(a, tree, node * 2, start, mid) + init2268(a, tree, node * 2 + 1, mid + 1, end);
}

void update2268(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    int mid = (start + end) / 2;

    if (index < start || end < index) return;
    if (start == end) {
        tree[node] += diff;
        return;
    }
    update2268(tree, node * 2, start, mid, index, diff);
    update2268(tree, node * 2 + 1, mid + 1, end, index, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum2268(vector<long long>& tree, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum2268(tree, node * 2, start, mid, left, right) + sum2268(tree, node * 2 + 1, mid + 1, end, left, right);
}



void n2268()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M;
    cin >> N >> M;
    vector<long long> a(N + 1);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);

    // init2268(a, tree, 1, 1, N);

    for (int i = 0; i < M;i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            if (x > y) swap(x, y);
            cout << sum2268(tree, 1, 1, N, x, y) << "\n";
        }
        else {
            long long diff = y - a[x];
            a[x] = y;
            update2268(tree, 1, 1, N, x, diff);
        }


    }
}

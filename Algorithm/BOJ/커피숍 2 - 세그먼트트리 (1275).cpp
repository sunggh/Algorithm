#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;


long long init1275(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init1275(a, tree, node * 2, start, mid) + init1275(a, tree, node * 2 + 1, mid + 1, end);
}

void update1275(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    int mid = (start + end) / 2;

    if (index < start || end < index) return;
    if (start == end) {
        tree[node] += diff;
        return;
    }
    update1275(tree, node * 2, start, mid, index, diff);
    update1275(tree, node * 2 + 1, mid + 1, end, index, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum1275(vector<long long>& tree, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum1275(tree, node * 2, start, mid, left, right) + sum1275(tree, node * 2 + 1, mid + 1, end, left, right);
}



void n1275()
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
    for (int i = 1; i < N + 1;i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    init1275(a, tree, 1, 1, N);

    for (int i = 0; i < M;i++) {
        int x, y, aa, b;
        cin >> x >> y >> aa >> b;
        if (x > y) swap(x, y);
        cout << sum1275(tree, 1, 1, N, x, y) << "\n";
        long long diff = b - a[aa];
        a[aa] = b;
        update1275(tree, 1, 1, N, aa, diff);
    }
}

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;


long long init1395(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init1395(a, tree, node * 2, start, mid) + init1395(a, tree, node * 2 + 1, mid + 1, end);
}
void update_lazy1395(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end) {
    if (Lazy[node] % 2 == 1) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            Lazy[node * 2] += Lazy[node];
            Lazy[node * 2 + 1] += Lazy[node];
        }
        Lazy[node] = 0;
    }

}
void update1395(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    update_lazy1395(tree, Lazy, node, start, end);
    if (left > end || start > right) return;
    if (start >= left && end <= right) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            Lazy[node * 2] += 1;
            Lazy[node * 2 + 1] += 1;
        }
        return;
    }
    update1395(tree, Lazy, node * 2, start, mid, left, right);
    update1395(tree, Lazy, node * 2 + 1, mid + 1, end, left, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum1395(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    update_lazy1395(tree, Lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum1395(tree, Lazy, node * 2, start, mid, left, right) + sum1395(tree, Lazy, node * 2 + 1, mid + 1, end, left, right);
}



void n1395()
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
    vector<long long> Lazy_tree(tree_size);

    for (int i = 0; i < M;i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            update1395(tree, Lazy_tree, 1, 1, N, x, y);
        }
        else {
            cout << sum1395(tree, Lazy_tree, 1, 1, N, x, y) << "\n";
        }


    }
}

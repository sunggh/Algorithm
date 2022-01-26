#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;


long long init10999(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init10999(a, tree, node * 2, start, mid) + init10999(a, tree, node * 2 + 1, mid + 1, end);
}
void update_lazy10999(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end) {
    if (Lazy[node] == 0) return;
    tree[node] += ((long long)end - start + 1) * Lazy[node];
    if (start != end) {
        Lazy[node * 2] += Lazy[node];
        Lazy[node * 2 + 1] += Lazy[node];
    }
    Lazy[node] = 0;
}
void update10999(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end, int left, int right, long long val) {
    int mid = (start + end) / 2;
    update_lazy10999(tree, Lazy, node, start, end);
    if (left > end || start > right) return;
    if (start >= left && end <= right) {
        tree[node] += ((long long)end - start + 1) * val;
        if (start != end) {
            Lazy[node * 2] += val;
            Lazy[node * 2 + 1] += val;
        }
        return;
    }
    update10999(tree, Lazy, node * 2, start, mid, left, right, val);
    update10999(tree, Lazy, node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum10999(vector<long long>& tree, vector<long long>& Lazy, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    update_lazy10999(tree, Lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum10999(tree, Lazy, node * 2, start, mid, left, right) + sum10999(tree, Lazy, node * 2 + 1, mid + 1, end, left, right);
}



void n10999()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> a(N + 1);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);
    vector<long long> Lazy_tree(tree_size);
    for (int i = 1; i < N + 1;i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    init10999(a, tree, 1, 1, N);

    for (int i = 0; i < M + K;i++) {
        long long x, y, z, r;
        cin >> x;
        if (x == 1) {
            cin >> y >> z >> r;
            update10999(tree, Lazy_tree, 1, 1, N, y, z, r);
        }
        else {
            cin >> y >> z;
            cout << sum10999(tree, Lazy_tree, 1, 1, N, y, z) << "\n";
        }


    }
}

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;


long long init11505(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = (init11505(a, tree, node * 2, start, mid) * init11505(a, tree, node * 2 + 1, mid + 1, end)) % 1000000007;
}

void update11505(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    int mid = (start + end) / 2;

    if (index < start || end < index) return;
    if (start == end) {
        tree[node] = diff;
        return;
    }
    update11505(tree, node * 2, start, mid, index, diff);
    update11505(tree, node * 2 + 1, mid + 1, end, index, diff);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

long long multply11150(vector<long long>& tree, int node, int start, int end, int left, int right) {
    int mid = (start + end) / 2;
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return (multply11150(tree, node * 2, start, mid, left, right) * multply11150(tree, node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}



void n11150()
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
    for (int i = 1; i < N + 1;i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    init11505(a, tree, 1, 1, N);
    for (int i = 0; i < M + K;i++) {
        long long x, y, z;
        cin >> x >> y >> z;

        if (x == 1) {
            update11505(tree, 1, 1, N, y, z);
        }
        else {
            cout << multply11150(tree, 1, 1, N, y, z) % 1000000007 << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    bool isValid;
    int left, right, len;
};

struct SegmentTree
{
    vector<Node> st;
    vector<int> a;
    int n;
    Node NEUTRO = {false, 0, 0, 0};
    SegmentTree(vector<int> &v): a(v) {
        n = a.size();
        st.resize(4 * n);
        build(1, 0, n);
    }

    Node merge(Node L, Node R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;
        Node res;
        res.len = L.len + R.len;
        res.left = L.left;
        res.right = R.right;
        if (L.isValid && R.isValid && L.right <= R.left) res.isValid = true;
        else res.isValid = false;
        return res;
    }

    void build(int node, int l, int r) {
        if (r - l == 1) {
            Node res;
            res.len = 1;
            res.left = a[l];
            res.right = a[l];
            res.isValid = true;
            st[node] = res;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid, r);
        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (l >= qr || ql >= r) return NEUTRO;
        if (l >= ql && qr >= r) return st[node];
        int mid = l + (r - l) / 2;
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid, r, ql ,qr);
        return merge(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &e: a) cin >> e;

    SegmentTree st(a);

    while (q--) {
        int l, r; cin >> l >> r;
        --l;
        cout << (st.query(1, 0, n, l, r).isValid? "YES\n": "NO\n");
    }

    return 0;
}
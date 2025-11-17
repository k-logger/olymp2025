#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)(1e9 + 1);
const int mod = (int)(1e9) - 7;

struct segtree {
    struct node {
        ll add = 0, val = 0;
    };
    vector<node> t;
    segtree(int sz) : t(4*sz) {}
    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr - tl == 1) {
            t[v].val = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v].val = t[2*v+1].val + t[2*v+2].val;
    }
    void upd(int v, int tl, int tr, int ql, int qr, int x) {
        if (tl >= ql && tr <= qr) {
            t[v].add += x;
            return;
        }
        if (tl >= qr || tr <= ql) return;

        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, ql, qr, x);
        upd(2*v+2, tm, tr, ql, qr, x);
    }
    ll get(int v, int tl, int tr, int i) {
        if (i >= tr || i < tl) return 0;
        if (tr - tl == 1) {
            return t[v].val + t[v].add;
        }
        int tm = (tl + tr) / 2;
        return t[v].add + get(2*v+1, tl, tm, i) + get(2*v+2, tm, tr, i);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    auto tree = segtree(n);
    tree.build(0, 0, n, a);
    int q; cin >> q;
    while (q--) {
        char c; cin >> c;
        if (c == 'g') {
            int x; cin >> x;
            x--;
            cout << tree.get(0, 0, n, x) << '\n';
        } else {
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            tree.upd(0, 0, n, l, r + 1, x);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

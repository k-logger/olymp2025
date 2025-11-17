#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)(1e9 + 1);
const int mod = (int)(1e9) - 7;

struct segtree {
    vector<int> t;
    segtree(int sz) : t(4*sz) {}

    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr - tl == 1) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    int get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= ql && tr <= qr) return t[v];
        if (tl >= qr || tr <= ql) return 0;

        int tm = (tl + tr) / 2;
        return get(2*v+1, tl, tm, ql, qr) + get(2*v+2, tm, tr, ql, qr);
    }

    void upd(int v, int tl, int tr, int i, int x) {
        if (i >= tr || i < tl) return;
        if (tr - tl == 1) {
            if (i % 2 == 1) {
                t[v] = -x;
            } else {
                t[v] = x;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 1) a[i] = -a[i];
    }
    auto tree = segtree(n);
    tree.build(0, 0, n, a);
    int q; cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            int ans = tree.get(0, 0, n, l, r + 1);
            if (l % 2 == 1) ans = -ans;
            cout << ans << '\n';
        } else {
            int i, j; cin >> i >> j;
            i--;
            tree.upd(0, 0, n, i, j);
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

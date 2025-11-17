#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)(1e9 + 1);

struct segtree {
    vector<int> t;
    segtree(int sz) : t(4 * sz) {}
    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr - tl == 1) {
            if (a[tl] == 0) {
                t[v] = 1;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = t[2*v+1] + t[2*v+2];
    }
    void upd(int v, int tl, int tr, int i, int x) {
        if (i < tl || i >= tr) return;
        if (tr - tl == 1) {
            if (x == 0) {
                t[v] = 1;
            } else {
                t[v] = 0;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    int find_k(int v, int tl, int tr, int k) {
        if (tr - tl == 1) {
            return tl;
        }
        int tm = (tl + tr) / 2;
        if (t[2*v+1] < k) {
            return find_k(2*v+2, tm, tr, k-t[2*v+1]);
        } else {
            return find_k(2*v+1, tl, tm, k);
        }
    }
    int get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= ql && tr <= qr) return t[v];
        if (tl >= qr || tr <= ql) return 0;
        int tm = (tl + tr) / 2;
        return get(2*v+1, tl, tm, ql, qr) + get(2*v+2, tm, tr, ql, qr);
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
        if (c == 'u') {
            int i, x; cin >> i >> x;
            i--;
            tree.upd(0, 0, n, i, x);
        } else {
            int l, r, k; cin >> l >> r >> k;
            l--; r--;
            int L = tree.get(0, 0, n, 0, l);
            int R = tree.get(0, 0, n, 0, r + 1);
            if (R - L < k) {
                cout << "-1\n";
            } else {
                cout << tree.find_k(0, 0, n, k + L) + 1 << '\n';
            }
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

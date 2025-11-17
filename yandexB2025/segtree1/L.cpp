#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)(1e15);
const int mod = (int)(1e9) - 7;

struct segtree {
    struct node {
        ll mx = -INF, mn = INF;
    };
    vector<node> t;
    segtree(int sz) : t(4*sz) {}
    node pull(node l, node r) {
        node res;
        res.mn = min(l.mn, r.mn);
        res.mx = max(l.mx, r.mx);
        return res;
    }
    void build(int v, int tl, int tr, vector<ll>& a) {
        if (tr - tl == 1) {
            t[v].mx = a[tl];
            t[v].mn = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }
    node get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= ql && tr <= qr) return t[v];
        if (tl >= qr || tr <= ql) return node{};
        int tm = (tl + tr) / 2;
        return pull(get(2*v+1, tl, tm, ql, qr), get(2*v+2, tm, tr, ql, qr));
    }
    void upd(int v, int tl, int tr, int i, ll x) {
        if (i >= tr || i < tl) return;
        if (tr - tl == 1) {
            t[v].mn += x;
            t[v].mx += x;
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    vector<ll> b(n);
    b[0] = a[0];
    for (int i=1; i < n; i++) b[i] = a[i] - a[i-1];
    auto tree = segtree(n);
    tree.build(0, 0, n, b);
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int x, y; cin >> x >> y;
            x--; y--;
            bool fl = (x < y);
            if (!fl) swap(x, y);
            auto res = tree.get(0, 0, n, x + 1, y + 1);
            if (fl) {
                if (res.mx <= 1) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            } else {
                if (res.mn >= -1) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            ll d; cin >> d;
            tree.upd(0, 0, n, l, d);
            if (r + 1 < n) tree.upd(0, 0, n, r + 1, -d);
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

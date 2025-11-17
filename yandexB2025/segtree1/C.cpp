#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)(1e9 + 1);

struct segtree {
    struct node {
        int pref = 0, suf = 0, ans = 0, sz = 0;
    };
    vector<node> t;
    segtree(int sz) : t(4 * sz) {}

    node pull(node l, node r) {
        node ans;
        ans.ans = max({l.ans, r.ans, l.suf + r.pref});
        ans.sz = l.sz + r.sz;
        ans.pref = l.pref;
        ans.suf = r.suf;
        if (l.pref == l.sz) ans.pref += r.pref;
        if (r.suf == r.sz) ans.suf += l.suf;
        return ans;
    }
    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr - tl == 1) {
            if (a[tl] == 0) {
                t[v].ans = 1;
                t[v].pref = 1;
                t[v].suf = 1;
            }
            t[v].sz = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }
    node get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= qr || tr <= ql) return node{};
        if (tl >= ql && tr <= qr) return t[v];
        int tm = (tl + tr) / 2;
        return pull(get(2*v+1, tl, tm, ql, qr), get(2*v+2, tm, tr, ql, qr));
    }
    void upd(int v, int tl, int tr, int i, int x) {
        if (i >= tr || i < tl) return;
        if (tr - tl == 1) {
            if (x == 0) {
                t[v].ans = 1;
                t[v].pref = 1;
                t[v].suf = 1;
            } else {
                t[v].ans = 0;
                t[v].pref = 0;
                t[v].suf = 0;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = pull(t[2*v+1], t[2*v+2]);
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
        string c; cin >> c;
        if (c == "UPDATE") {
            int i, x; cin >> i >> x;
            i--;
            tree.upd(0, 0, n, i, x);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << tree.get(0, 0, n, l, r + 1).ans << '\n';
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

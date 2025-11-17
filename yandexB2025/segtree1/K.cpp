#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)(1e9 + 1);
const int mod = (int)(1e9) - 7;

struct segtree {
    struct node {
        int open = 0, close = 0, ans = 0;
    };
    vector<node> t;
    segtree(int sz) : t(4*sz) {}

    node pull(node l, node r) {
        node res;
        res.open = l.open + r.open;
        res.close = l.close + r.close;
        res.ans = l.ans + r.ans + min(l.open-l.ans, r.close-r.ans);
        return res;
    }
    void build(int v, int tl, int tr, string& s) {
        if (tr - tl == 1) {
            if (s[tl] == '(') {
                t[v].open++;
            } else {
                t[v].close++;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, s);
        build(2*v+2, tm, tr, s);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }

    node get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= ql && tr <= qr) return t[v];
        if (tl >= qr || tr <= ql) return node{};
        int tm = (tl + tr) / 2;
        return pull(get(2*v+1, tl, tm, ql, qr), get(2*v+2, tm, tr, ql, qr));
    }
};

void solve() {
    string s; cin >> s;
    int q; cin >> q;
    int n = (int)(s.size());
    auto tree = segtree(n);
    tree.build(0, 0, n, s);
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << tree.get(0, 0, n, l, r + 1).ans*2 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

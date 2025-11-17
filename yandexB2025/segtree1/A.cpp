#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = (int)(1e9 + 1);
struct segtree {
    struct node {
        int val = -INF;
        int ind = -1;
    };
    vector<node> t;

    segtree(int sz) : t(4 * sz) {}
    node pull(node l, node r) {
        if (l.val > r.val) {
            return l;
        } else {
            return r;
        }
    }
    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr-tl == 1) {
            t[v].val = a[tl];
            t[v].ind = tl;
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
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    auto tree = segtree(n);
    tree.build(0, 0, n, a);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        auto ans = tree.get(0, 0, n, l, r + 1);
        cout << ans.val << " " << ans.ind + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

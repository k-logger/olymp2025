#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)(1e15);
const int mod = (int)(1e9) + 7;

struct segtree {
    struct node {
        ll mx = -INF;
    };
    vector<node> t;
    segtree(int sz) : t(4 * sz) {}

    node pull(node l, node r) {
        node res;
        res.mx = max(l.mx, r.mx);
        return res;
    }
    void build(int v, int tl, int tr, vector<int>& a) {
        if (tr - tl == 1) {
            t[v].mx = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }

    void upd(int v, int tl, int tr, int i, int x) {
        if (i < tl || i >= tr) return;
        if (tr - tl == 1 && i == tl) {
            t[v].mx = x;
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = pull(t[2*v+1], t[2*v+2]);
    }

    int find(int v, int tl, int tr, int x) {
        if (tr - tl == 1) {
            if (t[v].mx >= x) {
                return tl;
            } else {
                return -1;
            }
        }
        int tm = (tl + tr) / 2;
        if (t[2 * v + 1].mx >= x) return find(2 * v + 1, tl, tm, x);
        return find(2 * v + 2, tm, tr, x);
    }
    int find2(int v, int tl, int tr, int l, int x) {
        if (tr <= l) return -1;
        if (l <= tl) {
            if (t[v].mx >= x) return find(v, tl, tr, x);
            return -1;
        }
        int tm = (tl + tr) / 2;
        int left_son = 2 * v + 1;
        int left_ans = find2(left_son, tl, tm, l, x);
        if (left_ans != -1) return left_ans;
        return find2(2 * v + 2, tm, tr, l, x);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    auto tree = segtree(n);
    tree.build(0, 0, n, a);
    while (m--) {
        int c; cin >> c;
        if (c == 0) {
            int i, x; cin >> i >> x;
            i--;
            tree.upd(0, 0, n, i, x);
        } else {
            int i, x; cin >> i >> x;
            i--;
            int ans = tree.find2(0, 0, n, i, x);
            if (ans == -1) {
                cout << "-1\n";
            } else {
                cout << ans + 1 << '\n';
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

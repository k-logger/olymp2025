#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

const int INF = (int)(1e9);

struct segtree {
    struct node {
        int l = -1, r = 1e9 + 1;
        int ans = INF;
    };

    vector<node> t;
    segtree(int sz) : t(4 * sz) {}
    node pull(node l, node r) {
        if (l.l > r.l) swap(l, r);
        node res;
        if (l.ans == 0 || r.ans == 0 || r.l > l.r) {
            return node{0, 0, 0};
        }
        if (r.l <= l.r) {
            res.l = r.l;
            res.r = min(l.r, r.r);
        }
        res.ans = res.r - res.l;
        return res;
    }

    void build(int v, int tl, int tr, vector<pair<int, int>>& a) {
        if (tr - tl == 1) {
            t[v].l = a[tl].first;
            t[v].r = a[tl].second;
            t[v].ans = t[v].r - t[v].l;
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
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<pair<int, int>> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto tree = segtree(n);
    tree.build(0, 0, n, a);
    int cnt = 0;
    for (int i=0; i < n; i++) {
        int l = -1, r = i + 1;
        while (r-l > 1) {
            int m = (l + r) / 2;
            int res = tree.get(0, 0, n, m, i + 1).ans;
            if (res >= m1) r = m;
            else l = m;
        }
        int L = r;
        l = L-1, r = i + 1;
        while (r-l > 1) {
            int m = (l + r) / 2;
            int res = tree.get(0, 0, n, m, i + 1).ans;
            if (res <= m2) l = m;
            else r = m;
        }
        int R = l;
        cout << "L=" << L << " R=" << R << '\n';
        if (L > R) continue;
        cnt += R - L + 1;
    }
    cout << cnt;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

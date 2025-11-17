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
            t[v] += x;
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
    for (int i=0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i=0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    vector<int> L(n), R(n);
    auto st1 = segtree(n + 1), st2 = segtree(n + 1);
    for (int i=0; i < n; i++) {
        L[i] = st1.get(0, 0, n, a[i]+1, n + 1);
        st1.upd(0, 0, n, a[i], 1);
    }
    for (int i=n-1; i >= 0; i--) {
        R[i] = st2.get(0, 0, n, 0, a[i]);
        st2.upd(0, 0, n, a[i], 1);
    }

    ll ans = 0;
    for (int i=0; i < n; i++) ans += (ll)L[i] * (ll)R[i];
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

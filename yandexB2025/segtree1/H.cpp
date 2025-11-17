#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)(1e15);
const int mod = (int)(1e9) + 7;

struct segtree {
    vector<ll> t;
    segtree(int sz) : t(4 * sz) {}
    void build(int v, int tl, int tr, vector<ll>& a) {
        if (tr - tl == 1) {
            t[v] = a[tl]%mod;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm, tr, a);
        t[v] = (t[2*v+1] + t[2*v+2])%mod;
    }
    ll get(int v, int tl, int tr, int ql, int qr) {
        if (tl >= ql && tr <= qr) return t[v]%mod;
        if (tl >= qr || tr <= ql) return 0;
        int tm = (tl + tr) / 2;
        return (get(2*v+1, tl, tm, ql, qr) + get(2*v+2, tm, tr, ql, qr))%mod;
    }
    void upd(int v, int tl, int tr, int i, ll x) {
        if (i >= tr || i < tl) return;
        if (tr - tl == 1) {
            t[v] = (t[v] + x) % mod;
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v+1, tl, tm, i, x);
        upd(2*v+2, tm, tr, i, x);
        t[v] = (t[2*v+1] + t[2*v+2])%mod;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        int x; cin >> x;
        x--;
        a[i] = x;
    }
    vector<vector<ll>> dp(k + 1, vector<ll>(n));
    for (int i=0; i < n; i++) dp[1][i] = 1;
    for (int j = 2; j <= k; j++) {
        auto tree = segtree(n);
        for (int i=0; i < n; i++) {
            ll res = tree.get(0, 0, n, a[i] + 1, n);
            dp[j][i] = (dp[j][i] + res) % mod;
            tree.upd(0, 0, n, a[i], dp[j-1][i]);
        }
    }
    ll ans = 0;
    for (int i=0; i < n; i++) {
        ans = (ans + dp[k][i])%mod;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

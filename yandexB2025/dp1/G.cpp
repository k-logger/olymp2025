#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)(1e15);
const int mod = (int)(1e9) + 7;

ll f(string x) {
    if (x.size() == 1) return stoll(x) + 1;
    int n = (int)(x.size());
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(10)));
    for (int i=0; i <= (x[0]-'0'); i++) {
        dp[0][(i == (x[0]-'0'))][i] = 1;
    }
    for (int i=0; i < n-1; i++) {
        for (int fl = 0; fl < 2; fl++) {
            int max_digit = ((fl) ? x[i+1]-'0' : 9);
            for (int j=0; j <= max_digit; j++) {
                if (fl) {
                    int p = (x[i]-'0');
                    if (p > j) continue;
                    dp[i+1][(j == (x[i+1]-'0'))][j] = (dp[i+1][(j == (x[i+1]-'0'))][j] + dp[i][1][p])%mod;
                } else {
                    for (int p=0; p <= j; p++) {
                        dp[i+1][0][j] = (dp[i+1][0][j] + dp[i][0][p]) % mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i=0; i < 10; i++) {
        ans = (ans + dp[n-1][0][i] + dp[n-1][1][i])%mod;
    }
    return ans;
}


void solve() {
    string l, r; cin >> l >> r;
    bool fl = false;
    for (int i=0; i < (int)(l.size())-1; i++) {
        if (l[i + 1] < l[i]) {
            fl = true;
            break;
        }
    }
    cout << ((f(r) - f(l) + mod) % mod + (int)(!fl)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}

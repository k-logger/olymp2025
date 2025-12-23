#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

const int mod = 1050000011;

int bpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int x = bpow(a, n/2);
        return ((x%mod) * (x%mod))%mod;
    } else {
        return ((a%mod) * bpow(a, n-1))%mod;
    }
}

int inv(int x) {
    return bpow(x, mod-2);
}

int sq(int x) {
    int l = 0, r = (int)(1e9) + 1;
    while (r-l > 1) {
        int m = (l + r) / 2;
        if (m * m > x) r = m;
        else l = m;
    }
    return l;
}
void solve() {
    int n, m; cin >> n >> m;
    if (n == 2) {
        int t = sq(m);
        int k = t - 1;
        int k2 =(((k * (k + 1))%mod * (2 * k + 1))%mod * inv(3))%mod;
        int kk = ((k * (k + 1))%mod * inv(2))%mod;
        int ans = (k2 + kk + (t * (m - t * t + 1))%mod)%mod;
        cout << ans;
        return;
    }
    vector<vector<int>> dp(n, vector<int>(m + 1));
    for (int i=1; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i=1; i < n; i++) {
        for (int p=1; powl(p, i) <= m; p++) {
            int l = 0, r = mid;
            while (r-l > 1) {
                int mid = (l + r) / 2;
                int k = 1;
                int
                for (int j=0; j < mid; j++) {
                    if (k > )
                }
            }
            for (int j=1; powl(j, i + 1) <= m && powl(j, i + 1) <= powl(p, i); j++) {
                dp[i][j] = (dp[i][j] + dp[i-1][p])%mod;
            }
        }
    }
    int ans = 0;
    for (int i=1; i <= m; i++) ans = (ans + dp[n-1][i]) % mod;
    cout << ans;
}

signed main() {
    int t = 1;
    while (t--) solve();
}

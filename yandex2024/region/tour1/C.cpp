#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

const int mod = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> dp(n*m);
    vector<int> mp(n+1);
    mp[0] = 1;
    for (int i=1; i <= n; i++) {
        mp[i] = (mp[i-1] * m) % mod;
    }
    int ans = 0;
    for (int i=0; i < m; i++) {
        if (i > (s[0]-'a')) {
            dp[i-(s[0]-'a')] = 1;
            int k = 1;
            if (n > 1) {
                k = (k * (s[1]-'a'+1))%mod;
            }
            if (n > 2) {
                k = (k * mp[n-2])%mod;
            }
            ans = (ans + (dp[i-(s[0]-'a')] * k)%mod)%mod;
        }
    }
    int r = (s[0]-'a');
    for (int i=1; i < n; i++) {
        vector<int> next((n+1)*m);
        int k = 1;
        if (i < n - 1) {
            k = (k * (s[i+1]-'a'+1))%mod;
        }
        if (i < n - 2) {
            k = (k * mp[n-i-2])%mod;
        }
        for (int j=1; j < m-(s[i]-'a'); j++) {
            for (int sum=0; sum <= i*m-r; sum++) {
                next[sum+j] = (next[sum+j] + dp[sum])%mod;
                if ((sum+j)%(i+1) == 0) ans = (ans + (dp[sum] * k)%mod)%mod;
            }
        }
        dp = next;
        r += (s[i]-'a');
    }
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

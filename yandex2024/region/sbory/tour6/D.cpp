#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

const int mod = (int)(1e9) + 7;

int bpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int x = bpow(a, n/2)%mod;
        return (x*x)%mod;
    } else {
        return (a*bpow(a,n-1))%mod;
    }
}

void solve() {
    int n; cin >> n;
    if (n <= 3) {
        cout << n;
        return;
    }
    int ans = n%mod;
    vector<int> d;
    for (int i=2; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) d.push_back(n/i);
        }
    }
    sort(all(d));
    map<int, int> dp;
    for (auto& x : d) {
        int cnt = ((n/x - 1)%mod+mod)%mod;
        int t = (bpow(2, x) - 2 + mod)%mod;
        for (int i=2; i * i <= x; i++) {
            if (x % i == 0) {
               t = ((t - dp[i])%mod+mod)%mod;
               if (i*i != x) t = ((t - dp[x/i])%mod+mod)%mod;
            }
        }
        dp[x] = t;
        ans = (ans + (t*cnt)%mod) % mod;
    }
    cout << ans;
}

signed main() {
    int t=1;
    while (t--) solve();
}

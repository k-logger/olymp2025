#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

void solve() {
    int n; cin >> n;
    vector<int> p(n), b(n), a(n);
    int s = 0;
    for (int i=0; i < n; i++) {
            cin >> p[i];
            s += p[i];
    }
    for (int i=0; i < n; i++) cin >> b[i];
    for (int i=0; i < n; i++) {
            cin >> a[i];
    }
    int ans = 0;
    for (int m=0; m <= n; m++) {
        int res = 0;
        set<int> q;
        ans = m;
        for (int i=0; i < n; i++) {
            q.insert(a[i]);
        }
        for (int i=0; i < m; i++) {
            auto it = q.upper_bound(b[i]);
            if (it == q.end()) continue;
            q.erase(it);
            res += p[i];
        }
        vector<int> c;
        for (int i=0; i < n; i++) {
            auto it = q.find(a[i]);
            if (it != q.end()) c.push_back(a[i]);
        }
        int rr = 0;
        for (int i=0; i < sz(c); i++) {
            cout << "i=" << i << " c[i]=" << c[i] << " b[m+i]=" << b[m+i] << '\n';
            if (c[i] > b[m+i]) {
                rr += p[m+i];
            }
        }
        cout << "m=" << m << " rr=" << rr << " res=" << res << '\n';
        if (rr+res > s-rr-res) break;
        else if (m == n) {
            cout << -1;
            return;
        }
    }
    cout << ans;
}

signed main() {
    int t = 1;
    while (t--) solve();
}

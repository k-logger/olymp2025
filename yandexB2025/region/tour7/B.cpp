#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    int x = a[0][0];
    bool fl = false;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (a[i][j] != x) {
                fl = true;
            }
        }
    }
    if (!fl) {
        cout << min(n, (m + 1) / 2);
        return;
    }
    vector<vector<int>> b(n, vector<int>(m));
    vector<vector<int>> p(n, vector<int>(m + 1));
    for (int i=0; i < n; i++) {
        for (int j=1; j < m; j++) {
            b[i][j] = abs(a[i][j] - a[i][j-1]);
        }
    }
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            p[i][j + 1] = p[i][j] + b[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            int x = a[i][j];
            int l = 0, r = min({j+1, n-i, m-j});
            while (r-l > 1) {
                int k = (l + r) / 2;
                if (a[i+k][j-k] == x && p[i+k][j+k+1] - p[i+k][j-k+1] == 0) l = k;
                else r = k;
            }
            ans = max(ans, l + 1);
        }
    }
    cout << ans;
}

signed main() {
    int t = 1;
    while (t--) solve();
}

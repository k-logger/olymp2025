#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
const int INF = (int)(1e10);

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    sort(all(a));
    int cnt = 0;
    for (int i=1; i < n; i++) {
        if (a[i] - a[i-1] <= d) {
            cnt++;
            i++;
        }
    }
    cout << cnt;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

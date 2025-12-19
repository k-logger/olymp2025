#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
const int INF = (int)(1e15);
void solve() {
    int a1, b1, a2, b2, a3, b3; cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int ans = INF;
    for (int mask = 0; mask < (1 << 3); mask++) {
        vector<int> a = {a1, a2, a3};
        vector<int> b = {b1, b2, b3};
        for (int i=0; i < 3; i++) {
            if ((mask >> i) & 1) {
                swap(a[i], b[i]);
            }
        }
        vector<pair<int, int>> x = {{a[0], b[0]}, {a[1], b[1]}, {a[2], b[2]}};
        sort(all(x));
        do {
            auto& [A1, B1] = x[0];
            auto& [A2, B2] = x[1];
            auto& [A3, B3] = x[2];
            ans = min({ans, (A1 + A2 + A3)*max({B1, B2, B3}), (B1 + B2 + B3)*max({A1, A2, A3})});
            ans = min(ans, max(A1 + A3, A2 + A3) * max(B1 + B2, B3 + B2));
            ans = min(ans, max(A1 + A3, A2 + A3) * max(B1 + B2, B1 + B3));
            ans = min(ans, max(A3 + A2, A3 + A1) * max(B1 + B2, B3 + B2));
            ans = min(ans, max(A1 + A3, A2 + A3) * max(B1 + B2, B3 + B1));
        } while (next_permutation(all(x)));
    }
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

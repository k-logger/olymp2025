#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

const ld pi = acosl(-1);
const ld EPS = (ld)(1e-9);
void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (n > m) swap(n, m);
    cout << fixed << setprecision(9);
    if (k == 4) {
        cout << n * n;
        return;
    }
    if (k == 3) {
        ld l = 0, r = pi/6;
        while (r-l > EPS) {
            ld alpha = (l + r) / 2;
            ld a = n / cosl(alpha);
            ld x = a * cosl(pi/6 - alpha);
            if (m - x >= EPS) l = alpha;
            else r = alpha;
        }
        ld alpha = (l + r) / 2;
        ld a = n / cosl(alpha);
        // cout << "alpha=" << alpha << " a=" << a << '\n';
        ld S = ((a * a) * sqrtl(3)) / 4;
        cout << S;
        return;
    }
    cout << -1;

}

signed main() {
    int t=1;
    while (t--) solve();
}

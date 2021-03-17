#include <iostream>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        map <int, int> cnt;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a % m] += 1;
        }
        if (cnt[0]) ans = 1;
        for (int i = 1; i <= (m - 1) / 2; i++) {
            int p = cnt[i], q = cnt[m - i];
            if (p || q) {
                int mx = min(p, q);
                p -= mx; q -= mx;
                if (mx) {
                    ans += 1;
                    if (p > 0) {
                        p -= 1;
                    } else if (q > 0) {
                        q -= 1;
                    }
                }
                ans += (p + q);
            }
        }
        if (m % 2 == 0 && cnt[m / 2]) {
            ans += 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
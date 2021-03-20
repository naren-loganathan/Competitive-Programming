#include <iostream>
#include <vector>
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
        ll n; cin >> n;
        vector <ll> tag(n), s(n), dp(n);
        for (int i = 0; i < n; i++) {
            cin >> tag[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (tag[i] != tag[j]) {
                    ll di = dp[i], dj = dp[j];
                    dp[i] = max(dp[i], dj + abs(s[i] - s[j]));
                    dp[j] = max(dp[j], di + abs(s[i] - s[j]));
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
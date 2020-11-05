#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

ll M = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, d;
    cin >> n >> k >> d;
    vector < pair <ll, ll> > dp(n + 1, mp(0, 0));
    dp[0].fi = 1; dp[0].se = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = max((ll) 0, i - k); j < i; j++) {
            dp[i].se = (dp[i].se + dp[j].se) % M;
            if (j < i - (d - 1)) {
                dp[i].se = (dp[i].se + dp[j].fi) % M;
            }
        }
        for (ll j = max((ll) 0, i - (d - 1)); j < i; j++) {
            dp[i].fi = (dp[i].fi + dp[j].fi) % M;
        }
    }
    cout << dp[n].se << "\n";
    return 0;
}
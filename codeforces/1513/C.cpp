#include <iostream>
#include <vector>
#include <string>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7, N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <ll> dp(N, 0), d(10);
    dp[0] = 1; d[9] = 1; 
    for (int i = 1; i < N; i++) {
        vector <ll> d_new(10);
        for (int j = 1; j < 10; j++) {
            d_new[j] = d[j - 1];
        }
        d_new[0] = d[9];
        d_new[1] = (d_new[1] + d[9]) % mod;
        for (int j = 0; j < 10; j++) {
            dp[i] = (dp[i] + d_new[j]) % mod;
        }
        d = d_new;
    }
    int t; cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        for (int i = 0; i < 10; i++) {
            d[i] = 0;
        }
        while (n) {
            d[(n % 10)]++;
            n /= 10;
        }
        ll ans = 0;
        for (ll i = 0; i < 10; i++) {
            ll x = max(m - (9 - i), 0LL);
            ans = (ans + (dp[x] * d[i]) % mod) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
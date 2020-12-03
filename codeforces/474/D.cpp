#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, k, m = 1000000007, n = 100001; 
    cin >> t >> k;
    ll dp[n], p[n]; dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if (i >= k) {
            dp[i] = (dp[i] + dp[i - k]) % m;
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = (dp[i] + (i ? p[i - 1] : 0LL)) % m;
    }
    while (t--) {
        ll a, b; cin >> a >> b;
        cout << (p[b] - p[a - 1] + m) % m << "\n";
    }
    return 0;
}
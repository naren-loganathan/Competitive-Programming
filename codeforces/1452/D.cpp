#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 200005

ll gcd_extended (ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = (ll) 0; *y = (ll) 1;
        return b;
    }
    else {
        ll x1, y1;
        ll gcd = gcd_extended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
}   //gfg

ll mod_inv (ll a, ll M) {
    ll x, y;
    ll gcd = gcd_extended(a, M, &x, &y);
    return ((x % M + M) % M);
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll M = 998244353, dp[N][2];
    int n; cin >> n;
    dp[0][1] = 0; dp[1][0] = 2; dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] * 2) % M;
        dp[i][1] = (dp[i - 1][1] + dp[i - 2][1]) % M; //literally a fibonacci sequence
    }
    cout << (dp[n][1] * mod_inv(dp[n][0], M)) % M << "\n";
    return 0;
}
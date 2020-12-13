#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll dp[10000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m = 1000000007; 
    cin >> n;
    dp[0] = 1; dp[1] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[i] = (((dp[i - 1] * 2) % m) + ((dp[i - 2] * 3) % m)) % m;
    }
    cout << dp[n] << "\n";
    return 0;
}
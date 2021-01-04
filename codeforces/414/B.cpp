#include <iostream>
#include <vector>
using namespace std;
         
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;
         
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    vector < vector <ll> > dp(n + 1, vector <ll> (k + 1, 0));
    for (int j = 1; j <= k; j++) {
        for (int i = n; i > 0; i--) {
            if (j > 1) {
                dp[i][j] = dp[i][j - 1];
                for (int mul = 2 * i; mul <= n; mul += i) {
                    dp[i][j] = (dp[i][j] + dp[mul][j - 1]) % mod;
                }
            }
            else {
                dp[i][j] = 1;
            }
        }
    }
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[i][k]) % mod;
    }
    cout << result << "\n";
    return 0;
}

//dp[i][j], i -> starting numebr, j -> length of sequence
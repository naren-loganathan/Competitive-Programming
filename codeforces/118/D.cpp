#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int mod = 1e8;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int dp[n1 + 1][n2 + 1][2];
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int sum = 1; sum <= n1 + n2; sum++) {
        for (int i = max(sum - n2, 0); i <= min(n1, sum); i++) {
            dp[i][sum - i][0] = dp[i][sum - i][1] = 0;
            for (int j = 1; j <= min(i, k1); j++) {
                dp[i][sum - i][0] = (dp[i][sum - i][0] + dp[i - j][sum - i][1]) % mod;
            }
            for (int j = 1; j <= min(sum - i, k2); j++) {
                dp[i][sum - i][1] = (dp[i][sum - i][1] + dp[i][sum - i - j][0]) % mod;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << '\n';
    return 0;
}
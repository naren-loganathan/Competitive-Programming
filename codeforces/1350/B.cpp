#include <iostream>
#include <vector>
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
        int n; cin >> n;
        vector <int> s(n + 1), dp(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                if (s[j] > s[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result = max(result, dp[i]);
        }
        cout << result << "\n";
    }
    return 0;
}
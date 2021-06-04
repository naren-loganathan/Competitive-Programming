#include <iostream>
#include <string>
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
        string s; cin >> s;
        ll dp[s.length()][2];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = 0;
            }
        }
        if (s[0] == '0') {
            dp[0][0] = 1;
        } else if (s[0] == '1') {
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1; dp[0][1] = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                dp[i][0] = 1 + dp[i - 1][1];
            } else if (s[i] == '1') {
                dp[i][1] = 1 + dp[i - 1][0];
            } else {
                dp[i][0] = 1 + dp[i - 1][1];
                dp[i][1] = 1 + dp[i - 1][0];
            }
        }
        ll ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += max(dp[i][0], dp[i][1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
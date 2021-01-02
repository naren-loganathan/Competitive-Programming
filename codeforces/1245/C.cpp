#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    ll dp[s.length()][2];
    dp[0][0] = (s[0] != 'w' && s[0] != 'm' ? 1 : 0);    //0 -> w/o tinkering, 1 with
    dp[0][1] = 0;
    for (int i = 1; i < s.length(); i++) {
        if ((s[i] == 'u' || s[i] == 'n') && s[i] == s[i - 1]) {
            if (i == 1) {
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
            else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
                dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % mod;
            }
        }
        else {
            dp[i][0] = (s[i] != 'w' && s[i] != 'm' ? (dp[i - 1][1] + dp[i - 1][0]) % mod : 0);
            dp[i][1] = 0;
        }
    }
    cout << (dp[s.length() - 1][0] + dp[s.length() - 1][1]) % mod << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector < vector <ll> > dp(n + 1, vector <ll> (n + 1, -1e18));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] + a[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            }
        }
    }
    for (int j = n; j >= 0; j--) {
        if (dp[n][j] >= 0) {
            cout << j << '\n';
            break;
        }
    }
    return 0;
}
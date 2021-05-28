#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0; cin >> n;
    vector <int> a(n + 1), p(n + 1), start;
    start.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            start.push_back(i);
        }
        p[i] = p[i - 1] + a[i];
    }
    vector < vector <int> > dp(n + 1, vector <int> (n + 1, 1e9));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i - p[i], p.back()); j++) {
            if (a[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(start[j] - i));
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][p.back()]);
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector <int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        sort(t.begin(), t.end());
        vector < vector <int> > dp(n + 1, vector <int> (2 * n, 1e9));
        dp[0][0] = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                if (i < n) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - (j + 1)));
                }
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
       /* for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << dp[n][2 * n - 1] << "\n";
    }
    return 0;
}
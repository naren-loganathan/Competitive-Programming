#include <iostream>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n + 1], dp[n + 1][3]; //0 -> no work, 1 -> contest, 2 -> gym
    for (int i = 0; i <= n; i++) {
        if (i) {
            cin >> a[i];
        }
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if ((a[i] == 1 || a[i] == 3) && j != 1) {
                dp[i][1] = max(dp[i][1], dp[i - 1][j] + 1);
            }
            if ((a[i] == 2 || a[i] == 3) && j != 2) {
                dp[i][2] = max(dp[i][2], dp[i - 1][j] + 1);
            }
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        }
    }
    cout << n - max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";
    return 0;
}
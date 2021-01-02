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
    int n; cin >> n;
    vector <ll> h1(n), h2(n);
    ll dp[n][2];
    for (int i = 0; i < n; i++) {
        cin >> h1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h2[i];
    }
    dp[0][0] = h2[0]; dp[0][1] = h1[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + h2[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + h1[i]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    return 0;
}
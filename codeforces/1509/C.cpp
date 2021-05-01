#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, sum = 0; cin >> n;
    vector <ll> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    ll d[n][n], cost[n][n]; //cost[i][j] = minimum cost to get to subarray {i ... j}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 1e18;
            if (j >= i) {
                d[i][j] = s[j] - s[i];
            } else {
                d[i][j] = -1;
            }
        }
    }
    cost[0][n - 1] = d[0][n - 1];
    for (int sum = n - 2; sum >= 0; sum--) {
        for (int i = 0; i + sum < n; i++) {
            if (i) {
                cost[i][i + sum] = min(cost[i][i + sum], d[i][i + sum] + cost[i - 1][i + sum]);
            }
            if (i + sum < n - 1) {
                cost[i][i + sum] = min(cost[i][i + sum], d[i][i + sum] + cost[i][i + sum + 1]);
            }
        }
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, cost[i][i]);
    }
    cout << ans << '\n';
    return 0;
}
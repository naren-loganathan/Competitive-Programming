#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
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
        ll n, max_score = 0; cin >> n;
        vector <ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector <ll> dp(n + 1, 0);
        for (int i = n; i > 0; i--) {
            if (i + a[i] > n) {
                dp[i] = a[i];
            }
            else {
                dp[i] = a[i] + dp[i + a[i]];
            }
        }
        for (int i = 1; i <= n; i++) {
            max_score = max(max_score, dp[i]);
        }
        cout << max_score << "\n";
    }
    return 0;
}
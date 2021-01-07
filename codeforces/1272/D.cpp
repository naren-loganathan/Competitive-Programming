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
    int n, result = 0; cin >> n;
    int a[n], dp[n][2]; //0 -> w/o deletion, 1 -> w/
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1; dp[0][1] = 0; 
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = max(dp[i - 1][1] + 1, dp[i][0] - 1);
            if (i > 1 && a[i - 2] < a[i]) {
                dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
            }
        }
        else {
            dp[i][0] = 1;
            if (i > 1 && a[i - 2] < a[i]) {
                dp[i][1] = dp[i - 2][0] + 1;
            }
            else {
                dp[i][1] = 0;
            }
        }
        result = max(max(dp[i][0], dp[i][1]), result);
    }
    cout << result << "\n";
    return 0;
}


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
    int t; cin >> t;
    while (t--) {
        ll x, y, ans = 0; 
        cin >> x >> y;
        ll root = floor(sqrt(x));
        for (ll i = 1; i <= min(root, y - 1); i++) {
            ans += max(0LL, min(y, x / i - 1) - i);
        }
        cout << ans << "\n";
    }
    return 0;
}

//try being less dumb next time ༼ つ ◕_◕ ༽つ
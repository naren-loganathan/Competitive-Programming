#include <iostream>
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
        ll n; cin >> n;
        if (n % 2050) {
            cout << -1 << '\n';
        } else {
            ll x = n / 2050;
            int ans = 0;
            while (x) {
                ans += (x % 10);
                x /= 10;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
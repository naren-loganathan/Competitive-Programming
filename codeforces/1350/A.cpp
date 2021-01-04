#include <iostream>
#include <vector>
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
        ll n, k; cin >> n >> k;
        if (n % 2 == 0) {
            cout << n + 2 * k << "\n";
        }
        else {
            ll min_div = -1;
            for (ll i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    min_div = i;
                    break;
                }
            }
            if (min_div < 0) {
                min_div = n;
            }
            cout << n + min_div + 2 * (k - 1) << "\n";
        }
    }
    return 0;
}
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll a1 = a, b1 = b;
    if (a * b < 6 * n) {
        ll y = max(a, b), min_area = 1e18;
        for (ll x = min(a, b) ; x <= ceil(sqrt(6 * n)); x++) {
            if ((6 * n + x - 1) / x >= y) {
                if (x * ((6 * n + x - 1) / x) < min_area) {
                    min_area = x * ((6 * n + x - 1) / x); 
                    a1 = x; b1 = (6 * n + x - 1) / x;
                }
            }
        }
    }
    if (a1 < a) {
        swap(a1, b1);
    }
    cout << a1 * b1 << "\n" << a1 << " " << b1 << "\n";
    return 0;
}

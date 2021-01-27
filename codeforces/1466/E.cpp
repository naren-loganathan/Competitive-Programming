#include <iostream>
#include <vector>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <ll> pow2(60, 1);
    for (int i = 1; i < 60; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }
    int t; cin >> t;
    while (t--) {
        ll n, result = 0; cin >> n;
        vector <ll> x(n), fixed(60, 0);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            for (ll j = 0; j < 60; j++) {
                fixed[j] += (x[i] >> j) & 1;
            }
        }
        for (int i = 0; i < n; i++) {
            ll xi_and_xj = 0, xj_or_xk = 0;
            for (ll j = 0; j < 60; j++) {
                xi_and_xj = (xi_and_xj + ((x[i] >> j & 1 ? pow2[j] : 0) * fixed[j]) % mod) % mod;
                xj_or_xk = (xj_or_xk + ((x[i] >> j & 1 ? n : fixed[j]) * pow2[j]) % mod) % mod;
            }
            result = (result + ((xi_and_xj * xj_or_xk) % mod)) % mod;
        }
        cout << result << "\n";
    }
    return 0;
}

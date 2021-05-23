#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;
vector <ll> factorial(2e6 + 1, 1), pow_2(1e6 + 1, 1);

ll modular_power(ll x, ll y, ll mod) {
    ll result = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return result;
}

ll modular_inverse(ll n, ll mod) {
    return modular_power(n, mod - 2, mod);
}

ll modular_nCr(ll n, ll r, ll mod) {
    if (n < r) {
        return 0;
    } else if (r == 0) {
        return 1;
    } else {
        ll a = modular_inverse(factorial[r], mod);
        ll b = modular_inverse(factorial[n - r], mod);
        return ((((factorial[n] * a) % mod) * b) % mod);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 2; i <= 2e6; i++) {
        factorial[i] = (i * factorial[i - 1]) % mod;
    }
    vector <ll> sieve(1e6 + 1, -1), pow_2(1e6 + 1, 1);
    for (int i = 2; i <= 1e6; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j <= 1e6; j += i) {
                if (sieve[j] == -1) {
                    sieve[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= 1e6; i++) {
        pow_2[i] = (2 * pow_2[i - 1]) % mod;
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        ll ans = pow_2[y - 1];
        map <int, int> m;
        int a = x;
        while (a > 1) {
            m[sieve[a]] += 1;
            a /= sieve[a];
        }
        map <int, int> :: iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            ll multiplier = modular_nCr(it -> se + y - 1 , it -> se, mod);
            ans = (ans * multiplier) % mod; 
        }
        cout << ans << '\n';
    }
    return 0;
}
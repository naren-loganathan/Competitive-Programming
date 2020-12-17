#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 200005

ll M = 1e9 + 7, factorial[N] = {1};

ll modular_power (ll x, ll y, ll p) {
    ll result = 1;
    x %= p;
    while (y > 0) {
        if (y % 2) {
            result = (result * x) % p;
        }
        y /= 2;
        x = (x * x) % p;
    }
    return result;
}

ll modular_inverse(ll n, ll p) {
    return modular_power(n, p - 2, p);
}

ll modular_nCr(ll n, ll r, ll p) {
    if (n < r) {
        return 0;
    }
    else if (r == 0) {
        return 1;
    }
    else {
        ll a = modular_inverse(factorial[r], p);
        ll b = modular_inverse(factorial[n - r], p);
        return ((((factorial[n] * a) % p) * b) % p);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i < N; i++) {
        factorial[i] = (i * factorial[i - 1]) % M;
    }
    int t; cin >> t;
    while (t--) {
        ll n, m, k, cnt = 0; 
        cin >> n >> m >> k;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (ll i = m - 1; i < n; i++) {
            ll idx = lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();
            if (i - idx >= (m - 1)) {
                cnt = (cnt + modular_nCr(i - idx, m - 1, M)) % M;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
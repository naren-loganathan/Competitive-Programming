#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;
vector <ll> factorial(1001, 1);

ll modular_power (ll x, ll y, ll mod) {
    ll result = 1;
    x %= mod;
    while (y > 0) {
        if (y % 2) {
            result = (result * x) % mod;
        }
        y /= 2;
        x = (x * x) % mod;
    }
    return result;
}

ll modular_inverse (ll n, ll mod) {
    return modular_power(n, mod - 2, mod);
}

ll modular_nCr (ll n, ll r, ll mod) {
    if (n < r) {
        return 0;
    }
    else if (r == 0) {
        return 1;
    }
    else {
        ll a = modular_inverse(factorial[r], mod);
        ll b = modular_inverse(factorial[n - r], mod);
        return ((((factorial[n] * a) % mod) * b) % mod);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= 1000; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector <ll> a(n);
        map <ll, ll> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        sort(a.begin(), a.end());
        ll cnt = 0;
        for (int i = n - k; i < n; i++) {
            if (a[i] == a[i - 1]) {
                cnt++;
            }
            else {
                break;
            }
        }
        cout << modular_nCr(freq[a[n - k]], cnt, mod) << "\n";
    }
    return 0;
}
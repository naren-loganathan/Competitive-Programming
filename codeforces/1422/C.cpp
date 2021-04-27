#include <iostream>
#include <string>
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
    ll ans = 0;
    string n; cin >> n;
    vector <ll> num(n.length()), pow10(n.length(), 1);
    if (n.length() > 1) {
        num[n.length() - 2] = 1;
    }
    for (int i = 1; i < n.length(); i++) {
        pow10[i] = (10 * pow10[i - 1]) % mod;
    }
    for (int i = n.length() - 3; i >= 0; i--) {
        num[i] = ((pow10[n.length() - 2 - i] * (n.length() - 1 - i)) % mod + num[i + 1]) % mod;
    }
    for (ll i = 0; i < n.length(); i++) {
        ll add = n[i] - '0';
        if (add) {
            ll mul = num[i];
            if (i) {
                ll x = (i * (i + 1) / 2) % mod;
                x = (x * pow10[n.length() - 1 - i]) % mod;
                mul += x;
            }
            ans = (ans + (add * mul) % mod) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}
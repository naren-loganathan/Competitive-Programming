#include <iostream>
#include <string>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll gcd(ll a, ll b) {
    return (a ? gcd(b % a, a) : b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, ans; cin >> n;
        for (ll i = 0; i < 4; i++) {
            string s = to_string(n + i);
            ll sod_x = 0, x = n + i;
            for (int j = 0; j < s.length(); j++) {
                sod_x += (s[j] - '0');
            }
            if (gcd(x, sod_x) > 1) {
                ans = x; break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll gcd (ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll k, g = 0; cin >> k;
        vector <ll> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        for (int i = 1; i < n; i++) {
            g = gcd(g, x[i] - x[0]);
        }
        cout << ((k - x[0]) % g ? "NO" : "YES") << "\n";
    }
    return 0;
}

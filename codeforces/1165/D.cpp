#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
        bool possible = 1;
        ll n, x; cin >> n;
        vector <ll> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        x = d[0] * d[n - 1];
        for (int i = 0; i < n; i++) {
            if (x % d[i]) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            ll y = x, divisors = 1;
            for (int i = 2; i <= ceil(sqrt(y)); i += 2 - (i % 2 == 0)) {
                if (y % i == 0) {
                    ll cnt = 1;
                    while (y % i == 0) {
                        y /= i;
                        cnt++;
                    }
                    divisors *= cnt;
                }
            }
            if (y > 1) {
                divisors *= 2;
            }
            divisors -= 2;
            if (divisors != n) {
                possible = 0;
            }
        }
        if (possible) {
            cout << x << "\n";
        }
        else {
            cout << "-1" << "\n";
        }
    }
    return 0;
}
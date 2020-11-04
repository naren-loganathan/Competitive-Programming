#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll a, b; cin >> a >> b;
        if (b > 2 * a) {
            cout << a * (abs(x) + abs(y)) << "\n";
        }
        else {
            if (x * y > 0) {
                ll both = min(abs(x), abs(y));
                cout << b * both + a * (max(abs(x), abs(y)) - both) << "\n";
            }
            else {
                cout << a * (abs(x) + abs(y)) << "\n";
            }
        }
    }
    return 0;
}
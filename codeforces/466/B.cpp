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
    ll n, a, b, a1 = -1, b1 = -1;
    cin >> n >> a >> b;
    if (a * b < 6 * n) {
        for (ll area = 6 * n; area < 6 * (n + 1) && a1 == -1; area++) {
            for (ll i = 1; i <= ceil(sqrt(area)); i++) {
                if (area % i == 0) {
                    ll x = i, y = area / i;
                    if (x >= a && y >= b) {
                        a1 = x; b1 = y;
                        break;
                    }
                    else if (x >= b && y >= a) {
                        a1 = y; b1 = x;
                        break;
                    }
                }
            }
        }
    }
    else {
        a1 = a; b1 = b;
    }
    if (a1 == -1) {
        a1 = a; b1 = b;
        ll area1 = a * (((6 * n) + a - 1) / a);
        ll area2 = b * (((6 * n) + b - 1) / b);
        (area1 <= area2 ? b1 = ((6 * n) + a - 1) / a : a1 = ((6 * n) + b - 1) / b);
    }
    cout << a1 * b1 << "\n" << a1 << " " << b1 << "\n";
    return 0;
}

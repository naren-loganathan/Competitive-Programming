#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll a1 = a, b1 = b, a2 = a, b2 = b, n1 = n;
        ll m = min(a1 - x, n1);
        a1 -= m;
        n1 -= m;
        b1 -= min(b1 - y, n1);
        n1 = n;
        m = min(b2 - y, n1);
        b2 -= m;
        n1 -= m;
        a2 -= min(a2 - x, n1);
        cout << min(a1 * b1, a2 * b2) << "\n";
    }
    return 0;
}
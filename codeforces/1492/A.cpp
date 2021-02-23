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
    int t; cin >> t;
    while (t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        if (p % a == 0 || p % b == 0 || p % c == 0) {
            cout << "0" << "\n";
        }
        else {
            ll a1 = p % a, b1 = p % b, c1 = p % c;
            cout << min(a - a1, min(b - b1, c - c1)) << "\n";
        }
    }
    return 0;
}
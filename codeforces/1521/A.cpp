#include <iostream>
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
        ll A, B; cin >> A >> B;
        if (B == 1) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            ll x = A * (B - 1);
            ll y = A;
            ll z = A * B;
            if (B == 2) {
                x = A;
                y = 3 * A;
                z = x + y;
            }
            cout << x << ' ' << y << ' ' << z << '\n';
        }
    }
    return 0;
}
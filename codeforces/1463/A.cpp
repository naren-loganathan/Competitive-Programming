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
        ll a, b, c;
        cin >> a >> b >> c;
        bool possible = 1;
        a--; b--; c--;
        ll x = min(a, min(b, c));
        ll rem = a + b + c;
        if (rem / 9 > x || rem % 9 != 6) {
            possible = 0;
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
#include <iostream>
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
        ll a, b, c;
        cin >> a >> b >> c;
        ll x = -1, y = -1;
        if (a * b > c) {
            y = b;
            if (a < c) {
                x = 1;
            }
        }
        else {
            x = 1;
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}
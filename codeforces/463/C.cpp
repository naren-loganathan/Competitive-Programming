#include <iostream>
#include <vector>
#include <map>
using namespace std;
         
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
         
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x1, y1, x2, y2; cin >> n;
    ll a[n][n];
    map <int, ll> p, s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            p[i - j] += a[i][j];
            s[i + j] += a[i][j];
        }
    }
    ll mw = -1, mb = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll attack = p[i - j] + s[i + j] - a[i][j];
            if ((i + j) % 2) {
                if (attack > mw) {
                    mw = attack; x1 = i + 1; y1 = j + 1;
                }
            }
            else {
                if (attack > mb) {
                    mb = attack; x2 = i + 1; y2 = j + 1;
                }
            }
        }
    }
    cout << mw + mb << "\n";
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    return 0;
}
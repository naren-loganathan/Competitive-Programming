#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll d, k; cin >> d >> k;
        ld dd = d, kk = k;
        bool winner = 0;
        ld a = dd / sqrt(2);
        ll m = floor(a / kk);
        if (m * m * k * k + (m + 1) * (m + 1) * (k) * (k) <= d * d) {
            winner = 1;
        }
        cout << (winner ? "Ashish" : "Utkarsh") << "\n";
    }
    return 0;
}
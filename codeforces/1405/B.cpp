#include <iostream>
#include <vector>
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
        ll n; cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll pos = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                pos += a[i];
            }
            else {
                pos = max((ll) 0, pos + a[i]);
            }
        }
        cout << pos << "\n";
    }
    return 0;
}
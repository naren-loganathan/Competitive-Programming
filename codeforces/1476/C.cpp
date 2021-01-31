#include <iostream>
#include <vector>
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
        ll n, lsc = 0; cin >> n;
        vector <ll> c(n), a(n), b(n), len(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == b[i]) {
                len[i] = c[i] + 1LL;
            }
            else {
                len[i] = c[i] + 1LL + max(abs(a[i] - b[i]), len[i - 1] - abs(a[i] - b[i]));
            }
            lsc = max(len[i], lsc);
        }
        cout << lsc << "\n";
    }
    return 0;
}
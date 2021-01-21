#include <iostream>
#include <vector>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q; cin >> q;
    while (q--) {
        bool possible = 1;
        ll n, m; cin >> n >> m;
        vector <ll> l(n + 1, 0), h(n + 1, 0), t(n + 1, 0), min_temp(n + 1, m), max_temp(n + 1, m);
        for (ll i = 1; i <= n; i++) {
            cin >> t[i] >> l[i] >> h[i];
        }
        for (ll i = 1; i <= n; i++) {
            min_temp[i] = max(l[i], min_temp[i - 1] - t[i] + t[i - 1]);
            max_temp[i] = min(h[i], max_temp[i - 1] + t[i] - t[i - 1]);
            if (min_temp[i] > h[i] || max_temp[i] < l[i]) {
                possible = 0;
                break;
            }
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <set>
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
        ll n, k; cin >> n >> k;
        set <ll> s;
        ll g = 0;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            s.insert(a);
            g = max(g, a);
        }
        ll ans = 0;
        if (k) {
            ll mex = 0;
            while (s.find(mex) != s.end()) {
                mex += 1;
            }
            while (k--) {
                if (mex > g) {
                    ans += (k + 1);
                    break;
                }
                ll add = (g + mex) / 2 + ((g + mex) % 2);
                s.insert(add);
                ll prev_mex = mex;
                while (s.find(mex) != s.end()) {
                    mex += 1;
                }
                if (mex == prev_mex) break;
            }
        }
        cout << ans + s.size() << '\n';
    }
    return 0;
}
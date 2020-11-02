#include <iostream>
#include <cmath>
#include <vector>
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
        ll p, q; cin >> p >> q;
        if (p % q) {
            cout << p << "\n";
        }
        else {
            vector < pair <ll, ll> > candidates;
            for (int i = 2; i * i <= q; i++) {
                if (q % i == 0) {
                    ll count = 0;
                    while (q % i == 0) {
                        q /= i;
                        count++;
                    }
                    candidates.push_back(mp(i, count));
                }
            }
            if (q > 1) {
                candidates.push_back(mp(q, 1));
            }
            ll result = 1;
            for (int i = 0; i < candidates.size(); i++) {
                ll x = candidates[i].fi, count = candidates[i].se, fake_p = p;
                while (fake_p % x == 0) {
                    fake_p /= x;
                }
                for (int i = 1; i < count; i++) {
                    fake_p *= x;
                }
                result = max(result, fake_p);
            }
            cout << result << "\n";
        }
    }
    return 0;
}
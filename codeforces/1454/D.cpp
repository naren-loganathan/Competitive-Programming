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
        ll n, x; cin >> n;
        x = n;
        vector < pair <ll, ll> > factors;
        ll cnt = 0;
        while (x % 2 == 0) {
            cnt++;
            x /= 2;
        }
        factors.push_back(mp(2, cnt));
        for (ll i = 3; i <= ceil(sqrt(n)); i += 2) {
            if (x % i == 0) {
                cnt = 0;
                while (x % i == 0) {
                    cnt++;
                    x /= i;
                }
                factors.push_back(mp(i, cnt));
            }
        }
        if (x > 1) {
            factors.push_back(mp(x, 1));
        }
        ll m = 0;
        for (int i = 0; i < factors.size(); i++) {
            m = max(m, factors[i].se);
        }
        vector <ll> result(m, 1);
        for (int i = 0; i < factors.size(); i++) {
            for (int j = m - 1; j > m - factors[i].se - 1; j--) {
                result[j] *= factors[i].fi;
            }
        }
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
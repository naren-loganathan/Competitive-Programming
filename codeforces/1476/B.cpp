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
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector <ll> p(n), prefix(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            prefix[i] = (i ? p[i] + prefix[i - 1] : p[i]);
        }
        ll increment = 0;
        for (int i = 1; i < n; i++) {
            if (100 * p[i] > (prefix[i - 1] + increment) * k) {
                ll diff = 100 * p[i] - (prefix[i - 1] + increment) * k;
                ll cnt = diff / k + (diff % k ? 1 : 0);
                increment += cnt;
            }
        }
        cout << increment << "\n";
    }
    return 0;
}
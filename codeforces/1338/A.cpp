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
        ll n; cin >> n;
        vector <ll> a(n);
        ll T = 0, m = -1e18, d = -1e18;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m = max(a[i], m);
            d = max(m - a[i], d);
        }
        while ((1LL << T) < d + 1LL){
            T++;
        }
        cout << T << "\n";
    }
    return 0;
}
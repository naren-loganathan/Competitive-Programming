#include <iostream>
#include <vector>
#include <algorithm>
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
        ll n, cnt = 0; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (ll i = 2; i < n; i++) {
            ll idx = lower_bound(a.begin(), a.end(), a[i] - 2) - a.begin();
            if (i - idx >= 2) {
                cnt += (i - idx) * (i - idx - 1) / 2;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
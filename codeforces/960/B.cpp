#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    ll k = k1 + k2;
    vector <ll> a(n), b(n);
    multiset <ll, greater <ll> > d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i]) d.insert(abs(a[i] - b[i]));
    }
    while (k && !d.empty()) {
        ll curr = *d.begin();
        d.erase(d.find(curr));
        if (curr > 1) d.insert(curr - 1);
        k -= 1;
    }
    ll ans = 0;
    if (k && d.empty()) ans = k % 2;
    else {
        while (!d.empty()) {
            ll curr = *d.begin();
            d.erase(d.find(curr));
            ans += curr * curr;
        }
    }
    cout << ans << '\n';
    return 0;
}
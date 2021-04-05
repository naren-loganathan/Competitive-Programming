#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, ans = 0; cin >> n;
    vector <pair <ll, ll> > cities(n);
    for (int i = 0; i < n; i++) {
        ll a, c; cin >> a >> c;
        cities[i] = mp(a, c);
        ans += c;
    }
    sort(cities.begin(), cities.end());
    ll mx = cities[0].fi + cities[0].se;
    for (int i = 1; i < n; i++) {
        ans += max(0LL, cities[i].fi - mx);
        mx = max(mx, cities[i].fi + cities[i].se);
    }
    cout << ans << '\n';
    return 0;
}
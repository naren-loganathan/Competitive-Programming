#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll on_cells(ll n, ll x, ll y, ll time) {
    ll res = (1LL + 2 * time) * (1LL + 2 * time);   //getting the initial square.
    res -= 2 * time * (time + 1);   //removing the corners.
    ll r, l, d, u;
    r = max(0LL, x + time - n);
    l = max(0LL, 1 - x + time);
    d = max(0LL, y + time - n);
    u = max(0LL, 1 - y + time);
    res -= (r * r + l * l + u * u + d * d); //removing boundaries
    ll k1, k2, k3, k4;
    k1 = max(0LL, r + d - time - 1);
    k2 = max(0LL, d + l - time - 1);
    k3 = max(0LL, l + u - time - 1);
    k4 = max(0LL, u + r - time - 1);
    res += (k1 * (k1 + 1) / 2 + k2 * (k2 + 1) / 2 + k3 * (k3 + 1) / 2 + k4 * (k4 + 1) / 2);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, y, c;
    cin >> n >> x >> y >> c;
    ll l = 0, r = 2 * n - 2;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (on_cells(n, x, y, mid) >= c) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
    return 0;
}
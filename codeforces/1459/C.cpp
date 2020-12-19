#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll gcd (ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, b; cin >> n >> m;
    vector <ll> a(n), res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll g = (n == 1 ? 0 : a[1] - a[0]);
    for (int i = 2; i < n; i++) {
        g = gcd(a[i] - a[0], g);
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        res.push_back(gcd(a[0] + b, g));
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
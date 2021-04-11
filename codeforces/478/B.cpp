#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll nC2(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    ll x = n % m;
    cout << (m - x) * nC2(n / m) + x * nC2(n / m + 1) << ' ';
    cout << nC2(n - (m - 1)) << '\n';
    return 0;
}
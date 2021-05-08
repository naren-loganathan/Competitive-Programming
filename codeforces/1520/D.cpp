#include <iostream>
#include <map>
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
        map <ll, ll> m;
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            m[a - i - 1LL] += 1;
        }
        map <ll, ll> :: iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            ll add = ((it -> se - 1) * (it -> se) / 2);
            cnt += add;
        }
        cout << cnt << '\n';
    }
    return 0;
}
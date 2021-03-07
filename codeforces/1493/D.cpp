#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7, ans = 1, n, q;
vector <ll> smallest_div(2e5 + 1, 1), a(2e5 + 1, 1);

map <ll, ll>  cnt_div[200001];
multiset <ll> div_set[200001];

void update (ll i, ll x) {
    while (x > 1) {
        ll div = smallest_div[x], cnt = 0;
        while (smallest_div[x] == div) {
            cnt += 1; x /= smallest_div[x];
        }
        ll prev = cnt_div[i][div];
        cnt_div[i][div] += cnt;
        ll prev_power = 0;
        if (div_set[div].size() == n) {
            prev_power = *(div_set[div].begin());
        }
        div_set[div].insert(cnt_div[i][div]);
        if (prev) {
            div_set[div].erase(div_set[div].find(prev));
        }
        if (div_set[div].size() == n) {
            ll curr_power = *(div_set[div].begin());
            for (ll j = prev_power; j < curr_power; j++) {
                ans = (ans * div) % mod;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 2; i < 2e5 + 1; i++) {
        if (smallest_div[i] == 1) {
            smallest_div[i] = i;
            for (ll j = i * i; j < 2e5 + 1; j += i) {
                smallest_div[j] = i;
            }
        }
    }
    for (ll i = 0; i < n; i++) update(i, a[i]);
    while (q--) {
        ll i, x; cin >> i >> x;
        update(i - 1, x);
        cout << ans << '\n';
    }
    return 0;
}
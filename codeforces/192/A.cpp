#include <iostream>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t[100000];
    for (ll i = 0; i < 100000; i++) {
        t[i] = i * (i + 1) / 2;
    }
    ll n; cin >> n;
    bool possible = 0;
    for (int i = 1; i * (i + 1) / 2 < n; i++) {
        ll x = n - t[i];
        if (t[lower_bound(t, t + 100000, x) - t] == x) {
            possible = 1;
            break;
        } 
    }
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}
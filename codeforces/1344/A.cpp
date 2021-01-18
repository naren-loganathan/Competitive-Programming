#include <iostream>
#include <vector>
#include <set>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mul = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set <ll> shifts;
        for (ll i = 0; i < n; i++) {
            shifts.insert((i + a[i] + n * mul) % n);
        }
        cout << (shifts.size() == n ? "Yes" : "No") << "\n";
    }
    return 0;
}

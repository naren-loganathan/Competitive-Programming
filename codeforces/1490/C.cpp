#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <ll> cubes(1e4 + 1, 0);
    for (ll i = 1; i <= 1e4; i++) {
        cubes[i] = i * i * i;
    }
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        bool possible = 0;
        for (ll i = 1; cubes[i] < x && !possible; i++) {
            ll a = x - cubes[i];
            int lo = 1, hi = 1e4, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (cubes[mid] > a) {
                    hi = mid - 1;
                }
                else if (cubes[mid] < a) {
                    lo = mid + 1;
                }
                else {
                    possible = 1;
                    break;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
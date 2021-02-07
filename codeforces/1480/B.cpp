#include <iostream>
#include <vector>
#include <cmath>
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
        bool possible = 1;
        ll A, B, n, worst_hit = 0, dmg = 0; 
        cin >> A >> B >> n;
        vector <ll> a(n), b(n), hits(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            worst_hit = max(worst_hit, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            hits[i] = (b[i] + A - 1LL) / A;
            dmg += hits[i] * a[i];
        }
        if (dmg - worst_hit > B) {
            possible = 0;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
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
    int q; cin >> q;
    while (q--) {
        bool possible = 0;
        ll u, v; cin >> u >> v;
        if (u == v) {
            possible = 1;
        }
        else if (u < v) {
            possible = 1;
            vector <int> bits_u(31, 0), bits_v(31, 0);
            for (ll i = 0; i <= 30; i++) {
                if (u & (1LL << i)) bits_u[i] = 1;
                if (v & (1LL << i)) bits_v[i] = 1;
            }
            int b = 0;
            for (ll i = 0; i <= 30 && possible; i++) {
                if (bits_v[i] == 1) {
                    while (bits_u[b] != 1 && b <= i) {
                        b += 1;
                    }
                    if (b > i) possible = 0;
                    else b += 1;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }   
    return 0;
}
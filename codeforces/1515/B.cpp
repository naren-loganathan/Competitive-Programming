#include <iostream>
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
        int n; cin >> n;
        bool poss = 1;
        if (n % 2) {
            poss = 0;
        } else {
            n /= 2;
            int r2 = floor(sqrt(n));
            if (r2 * r2 != n) {
                if (n % 2) {
                    poss = 0;
                } else {
                    n /= 2;
                    int r4 = floor(sqrt(n));
                    if (r4 * r4 != n) {
                        poss = 0;
                    }
                }
            }
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}
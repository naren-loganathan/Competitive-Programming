#include <iostream>
using namespace std;

typedef long long ld;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n % 2 == 1) {
            cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
        } else {
            if (n % 4 == 0) {
                cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
            } else {
                n /= 2;
                cout << 2 * 1 << ' ' << 2 * (n / 2) << ' ' << 2 * (n / 2) << '\n';
            }
        }
    }
    return 0;
}
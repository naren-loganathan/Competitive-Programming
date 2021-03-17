#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ld;
#define fi first
#define se second
#define mp make_pair

int p[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < k - 3; i++) {
            cout << 1 << ' ';
        }
        int q = n - (k - 3);
        if (q % 2 == 1) {
            cout << 1 << ' ' << q / 2 << ' ' << q / 2 << '\n';
        } else {
            if (q % 4 == 0) {
                cout << q / 2 << ' ' << q / 4 << ' ' << q / 4 << '\n';
            } else {
                q /= 2;
                cout << 2 * 1 << ' ' << 2 * (q / 2) << ' ' << 2 * (q / 2) << '\n';
            }
        }
    }
    return 0;
}
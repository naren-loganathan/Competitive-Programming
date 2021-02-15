#include <iostream>
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
        int n, k; cin >> n >> k;
        if (n % 2 == 0) {
            cout << (k % n ? k % n : n) << "\n";
        }
        else {
            if (k <= n / 2) {
                cout << k << "\n";
            }
            else {
                int pos = 1; k--;
                int shifts = k / (n / 2);
                pos += shifts * (n / 2 + 1);
                pos += k % (n / 2);
                cout << (pos % n ? pos % n : n) << "\n";
            }
        }
    }
    return 0;
}
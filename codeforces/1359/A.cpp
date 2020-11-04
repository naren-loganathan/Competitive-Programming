#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (m <= n / k) {
            cout << m << "\n";
        }
        else {
            int res = (m - n / k) / (k - 1);
            cout << (n / k - ((m - n / k) % (k - 1) ? res + 1 : res)) << "\n";
        }
    }
    return 0;
}
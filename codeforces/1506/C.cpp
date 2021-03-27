#include <iostream>
#include <string>
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
        string a, b; cin >> a >> b;
        int n = a.length(), m = b.length(), len = 0;
        for (int i = min(n, m); i > 0 && len == 0; i--) {
            for (int j = 0; j < n - i + 1; j++) {
                for (int k = 0; k < m - i + 1; k++) {
                    if (a.substr(j, i) == b.substr(k, i)) {
                        len = i; break;
                    }
                }
            }
        }
        cout << n + m - 2 * len << '\n';
    }
    return 0;
}
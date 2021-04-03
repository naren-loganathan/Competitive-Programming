#include <iostream>
#include <string>
#include <vector>
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
        string a, b; cin >> a >> b;
        vector <int> cnta(n), cntb(n);
        cnta[0] = a[0] - 48;
        cntb[0] = b[0] - 48;
        for (int i = 1; i < n; i++) {
            cnta[i] = cnta[i - 1] + (a[i] == '1');
            cntb[i] = cntb[i - 1] + (b[i] == '1');
        }
        int parity = 0;
        bool poss = 1;
        for (int i = n - 1; i >= 0; i--) {
            if ((a[i] != b[i] && parity % 2 == 0) || (a[i] == b[i] && parity % 2)) {
                if ((i + 1) % 2 || cnta[i] != cntb[i] || cnta[i] != (i + 1) / 2) {
                    poss = 0; break;
                } else {
                    parity += 1;
                }
            }
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}
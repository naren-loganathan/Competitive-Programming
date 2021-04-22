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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n), bits[30];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 30; j++) {
                bits[j].push_back((1LL << j) & a[i] ? 1 : 0);
            }
            if (i) {
                for (int j = 0; j < 30; j++) {
                    bits[j][i] += bits[j][i - 1];
                }
            }
        }
        bool two = false, three = false;
        for (int i = 0; i < n - 1; i++) {
            bool ok = true;
            for (int j = 0; j < 30; j++) {
                if (bits[j][i] % 2 != (bits[j][n - 1] - bits[j][i]) % 2) {
                    ok = false; break;
                }
            }
            if (ok) {
                two = true; break;
            }
        }
        if (two) {
            cout << "YES" << '\n';
        } else if (n > 2) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    bool ok = true;
                    for (int k = 0; k < 30; k++) {
                        if ((bits[k][i] % 2) != ((bits[k][j] - bits[k][i]) % 2) || ((bits[k][j] - bits[k][i]) % 2) != ((bits[k][n - 1] - bits[k][j])) % 2) {
                            ok = false; break;
                        }
                    }
                    if (ok) {
                        three = true; break;
                    }
                }
            }
            cout << (three ? "YES" : "NO") << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
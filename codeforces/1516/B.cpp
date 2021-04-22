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
        vector <int> a(n), axor(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            axor[i] = a[i];
            if (i) {
                axor[i] ^= axor[i - 1];
            }
        }
        bool poss = 0;
        for (int i = 0; i < n - 1 && !poss; i++) {
            if (axor[i] == (axor[n - 1] ^ axor[i])) {
                poss = 1; break;
            } else {
                for (int j = i + 1; j < n - 1; j++) {
                    if (axor[i] == (axor[j] ^ axor[i]) && (axor[j] ^ axor[i]) == (axor[n - 1] ^ axor[j])) {
                        poss = 1; break;
                    }
                }
            }
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}
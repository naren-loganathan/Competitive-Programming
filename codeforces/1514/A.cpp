#include <iostream>
#include <vector>
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
        vector <int> a(n), b(n, 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int cnt = 0;
            while (a[i] % 2 == 0) {
                a[i] /= 2; cnt++;
            }
            if (cnt % 2) b[i] *= 2;
            for (int j = 3; j <= ceil(sqrt(a[i])); j += 2) {
                if (a[i] % j == 0) {
                    cnt = 0;
                    while (a[i] % j == 0) {
                        a[i] /= j; cnt++;
                    }
                    if (cnt % 2) b[i] *= j;
                }
            }
            b[i] *= a[i];
        }
        bool poss = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] != 1) {
                poss = 1; break;
            }
        }
        cout << (poss ? "YES" : "NO") << '\n' ;
    }
    return 0;
}
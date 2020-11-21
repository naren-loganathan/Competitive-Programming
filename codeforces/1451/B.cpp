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
        int n, q, l, r; 
        cin >> n >> q;
        string s; cin >> s;
        int onef = n + 1, onel = -1, zerof = n + 1, zerol = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (zerof == n + 1) {
                    zerof = i;
                }
                zerol = i;
            }
            if (s[i] == '1') {
                if (onef == n + 1) {
                    onef = i;
                }
                onel = i;
            }
        }
        while (q--) {
            bool possible = 0;
            cin >> l >> r;
            if (s[l - 1] == '1') {
                if (onef < l - 1) {
                    possible = 1;
                }
            }
            if (s[l - 1] == '0') {
                if (zerof < l - 1) {
                    possible = 1;
                }
            }
            if (s[r - 1] == '1') {
                if (onel > r - 1) {
                    possible = 1;
                }
            }
            if (s[r - 1] == '0') {
                if (zerol > r - 1) {
                    possible = 1;
                }
            }
            cout << (possible ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
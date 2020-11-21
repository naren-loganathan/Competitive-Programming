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
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        bool possible = 1;
        vector <int> fa(26, 0), fb(26, 0);
        for (int i = 0; i < n; i++) {
            fa[a[i] - 97]++;
            fb[b[i] - 97]++;
        }
        for (int i = 0; i < 26; i++) {
            if (i < 25) {
                if (fa[i] < fb[i]) {
                    possible = 0;
                    break;
                }
                if ((fa[i] - fb[i]) % k) {
                    possible = 0;
                    break;
                }
                else {
                    fa[i + 1] += (fa[i] - fb[i]);
                }
            }
            if (i == 25) {
                if (fa[i] != fb[i]) {
                    possible = 0;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
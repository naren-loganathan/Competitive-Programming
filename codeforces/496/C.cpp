#include <iostream>
#include <vector>
#include <string>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector <string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }
    if (n == 1) cout << 0 << '\n';
    else {
        int cnt = 0;
        vector <bool> g(n, 0);
        for (int j = 0; j < m; j++) {
            bool remove = 0;
            vector <bool> new_g(n, 0);
            for (int i = 1; i < n; i++) {
                if (table[i][j] > table[i - 1][j]) {
                    new_g[i] = 1;
                }
                else if (table[i][j] < table[i - 1][j]) {
                    if (g[i] == 0) {
                        cnt += 1; remove = 1;
                        break;
                    }
                }
            }
            if (!remove) {
                for (int i = 1; i < n; i++) {
                    g[i] = (g[i] || new_g[i]);
                }
            }
        }
        cout << cnt << '\n'; 
    }
    return 0;
}
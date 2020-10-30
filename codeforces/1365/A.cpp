#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m, a; 
        cin >> n >> m;
        vector <bool> rows(n, 1), columns(m, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a) {
                    rows[i] = 0;
                    columns[j] = 0;
                }
            }
        }
        int p = 0, q = 0;
        for (int i = 0; i < n; i++) {
            if (rows[i]) {
                p++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (columns[i]) {
                q++;
            }
        }
        cout << (min(p, q) % 2 ? "Ashish" : "Vivek") << "\n";
    }
    return 0;
}
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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector <string> edges(n);
        for (int i = 0; i < n; i++) {
            cin >> edges[i];
        }
        if (m % 2) {
            cout << "YES" << "\n";
            for (int i = 0; i <= m; i++) {
                cout << (i % 2 ? "2" : "1") << " ";
            }
            cout << "\n";
        }
        else {
            bool possible = 0;
            int id_1, id_2;
            for (int i = 0; i < n && !possible; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (edges[i][j] == edges[j][i]) {
                        possible = 1;
                        id_1 = i + 1; id_2 = j + 1;
                        break;
                    }
                }
            }
            if (possible) {
                cout << "YES" << "\n";
                for (int i = 0; i <= m; i++) {
                    cout << (i % 2 ? id_1 : id_2) << " ";
                }
                cout << "\n";
            }
            else {
                if (n > 2) {
                    vector <int> a(n, 0), b(n, 0);
                    cout << "YES" << "\n";
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (edges[i][j] == 'a') {
                                a[i] = j + 1;
                            }
                            else if (edges[i][j] == 'b') {
                                b[i] = j + 1;
                            }
                        }
                    }
                    bool done = 0;
                    vector <int> cycle(3);
                    for (int i = 0; i < n && !done; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((edges[i][j] == 'a' && a[j]) || (edges[i][j] == 'b' && b[j])) {
                                cycle[0] = i + 1; 
                                cycle[1] = j + 1;
                                cycle[2] = (edges[i][j] == 'a' ? a[j] : b[j]); 
                                done = 1; break;
                            }
                        }
                    }
                    for (int i = 0; i <= m; i++) {
                        if ((i + ((m / 2) % 2 == 0)) % 4 == 0) {
                            cout << cycle[0] << " ";
                        }
                        else if ((i + ((m / 2) % 2 == 0)) % 4 == 2) {
                            cout << cycle[2] << " ";
                        }
                        else {
                            cout << cycle[1] << " ";
                        }
                    }
                }
                else {
                    cout << "NO" << "\n";
                }
            }
        }
    }
    return 0;
}
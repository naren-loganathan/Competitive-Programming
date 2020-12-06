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
        int n; cin >> n;
        vector <string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int x = 0, y = 0;   // a -> X's, b -> O's
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a != b) {
                    int op = 0, k = 0;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (grid[i][j] == 'X' || grid[i][j] == 'O') {
                                k++;
                            }
                            if (((i + j) % 3) == a && grid[i][j] == 'O') {
                                op++;
                            }
                            if (((i + j) % 3) == b && grid[i][j] == 'X') {
                                op++;
                            }
                        }
                    }
                    if (op <= k / 3) {
                        x = a; y = b;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (((i + j) % 3) == x && grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
                if (((i + j) % 3) == y && grid[i][j] == 'X') {
                    grid[i][j] = 'O';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << grid[i] << "\n";
        }
    }
    return 0;
}
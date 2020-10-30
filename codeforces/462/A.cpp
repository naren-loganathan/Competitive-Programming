#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    bool uhuh = 1;
    vector <string> grid(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] += "x";
        grid[i].insert(0, "x");
    }
    string border = "";
    for (int i = 0; i < n + 2; i++) {
        border += "x";
    }
    grid[0] = border;
    grid[n + 1] = border;
    for (int i = 1; i <= n; i++) {
        if (!uhuh) {
            break;
        }
        for (int j = 1; j <= n; j++) {
            int count = 0;
            if (grid[i - 1][j] == 'o') {
                count++;
            }
            if (grid[i + 1][j] == 'o') {
                count++;
            }
            if (grid[i][j - 1] == 'o') {
                count++;
            }
            if (grid[i][j + 1] == 'o') {
                count++;
            }
            if (count % 2) {
                uhuh = 0;
                break;
            }
        }
    }
    cout << (uhuh ? "YES" : "NO") << "\n";
    return 0;
}
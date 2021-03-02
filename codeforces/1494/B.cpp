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
        bool possible = 0;
        int n; cin >> n;
        vector <int> b(4);
        for (int i = 0; i < 4; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < 16; i++) {
            bool solution = 1;
            vector <int> temp = b;
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) {
                    temp[j] -= 1;
                    temp[(j + 1) % 4] -= 1;
                }
            }
            for (int j = 0; j < 4; j++) {
                if (temp[j] < 0 || temp[j] > n - 2) solution = 0;
            }
            possible |= solution;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
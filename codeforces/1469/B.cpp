#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
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
        int n, m, num, result = 0;
        cin >> n;
        vector <int> r(n);
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        cin >> m;
        vector <int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 1; i < n; i++) {
            r[i] += r[i - 1];
        }
        for (int i = 1; i < m; i++) {
            b[i] += b[i - 1];
        }
        int max_r = 0, max_b = 0;
        for (int i = 0; i < n; i++) {
            max_r = max(max_r, r[i]);
        }
        for (int i = 0; i < m; i++) {
            max_b = max(max_b, b[i]);
        }
        cout << max(0, max_r + max_b) << "\n";
    }
    return 0;
}
#include <iostream>
#include <string>
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
        int n, m, x = 0; cin >> n >> m;
        string s; cin >> s;
        vector <int> val(n + 1, 0), minl(n + 1, 1e6), minr(n + 1, 1e6), maxl(n + 1, 0), maxr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '+') {
                x++;
            }
            else {
                x--;
            }
            val[i] = x;
            minl[i] = min(minl[i - 1], val[i]);
            maxl[i] = max(maxl[i - 1], val[i]);
        }
        minr[n] = val[n]; maxr[n] = val[n];
        for (int i = n - 1; i > 0; i--) {
            minr[i] = min(minr[i + 1], val[i]);
            maxr[i] = max(maxr[i + 1], val[i]);
        }
        while (m--) {
            int l, r, largest = 0, smallest = 0;
            cin >> l >> r;
            int delta = val[r] - val[l - 1];
            if (r == n) {
                if (l != 1) {
                    largest = maxl[l - 1];
                    smallest = minl[l - 1];
                }
            }
            else if (l == 1) {
                largest = maxr[r + 1] - delta;
                smallest = minr[r + 1] - delta;
            }
            else {
                largest = max(maxl[l - 1], maxr[r + 1] - delta);
                smallest = min(minr[r + 1] - delta, minl[l - 1]);
            }
            cout << largest - smallest + 1 + (largest < 0 || smallest > 0) << "\n";
        }
    }
    return 0;
}
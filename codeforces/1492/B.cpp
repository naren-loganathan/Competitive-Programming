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
        int n; cin >> n;
        vector <int> p(n), ord, mx(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            mx[i] = (i ? max(p[i], mx[i - 1]) : p[i]);
        }
        int i = n - 1, bd = n - 1;
        while (i >= 0) {
            if (p[i] == mx[i]) {
                for (int j = i; j <= bd; j++) {
                    ord.push_back(p[j]);
                }
                bd = i - 1;
            }
            i--;
        }
        for (int i = 0; i < n; i++) {
            cout << ord[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
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
        int n, x; cin >> n >> x;
        vector <int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        int curr = 0;
        bool poss = 1;
        for (int i = 0; i < n; i++) {
            curr += w[i];
            if (curr == x) {
                if (w[i] != w.back()) {
                    curr += w[n - 1] - w[i];
                    swap(w[i], w[n - 1]);
                } else {
                    poss = 0;
                }
            }
        }
        if (poss) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << w[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
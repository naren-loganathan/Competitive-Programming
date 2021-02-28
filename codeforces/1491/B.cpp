#include <iostream>
#include <vector>
#include <map>
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
        int n, u, v; 
        cin >> n >> u >> v;
        vector <int> a(n + 1);
        bool gap = 0;
        map <int, int> cnt;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            if (i > 1) {
                if (abs(a[i] - a[i - 1]) > 1) gap = 1;
            }
        }
        if (gap) cout << "0" << "\n";
        else {
            if (u > v) {
                if (cnt[a[1]] == n) {
                    cout << 2 * v << "\n";
                }
                else {
                    cout << v << "\n";
                }
            }
            else {
                if (cnt[a[1]] == n) {
                    cout << u + v << "\n";
                }
                else {
                    cout << u << "\n";
                }
            }
        }
    }
    return 0;
}
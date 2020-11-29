#include <iostream>
#include <vector>
#include <string>
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
        int n, p, k;
        cin >> n >> p >> k;
        string a; cin >> a;
        int x, y; cin >> x >> y;
        vector <int> t(k, 0);
        int c = 0, cost = n * max(x, y);
        for (int i = n - 1; i >= p - 1; i--) {
            if (a[i] == '0') {
                t[i % k]++;
            }
            c = (i - (p - 1)) * y + t[i % k] * x;
            cost = min(c, cost);
        }
        cout << cost << "\n";
    }
    return 0;
}
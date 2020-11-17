#include <iostream>
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
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s; cin >> s;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cost += min(c1, c0 + h);
            }
            else {
                cost += min(c0, c1 + h);
            }
        }
        cout << cost << "\n";
    }
    return 0;
}
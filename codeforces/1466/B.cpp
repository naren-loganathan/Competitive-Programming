#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
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
        vector <int> x(n);
        vector <bool> freq(2 * n + 2, 0);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            if (freq[x[i]] == 0) {
                freq[x[i]] = 1;
            }
            else {
                if (freq[x[i] + 1] == 0) {
                    freq[x[i] + 1] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= 2 * n + 1; i++) {
            if (freq[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
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
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        set <int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(x[i] - x[j])) {
                    s.insert(abs(x[i] - x[j]));
                }
            }
        }
        cout << s.size() << "\n";
    }
    return 0;
}
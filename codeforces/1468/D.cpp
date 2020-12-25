#include <iostream>
#include <vector>
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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector <int> s(m);
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int time_detonate, num_drop = abs(a - b) - 1;
        if (a < b) {
            time_detonate = b - 2;
        }
        else {
            time_detonate = n - b - 1;
        }
        int lim = lower_bound(s.begin(), s.end(), time_detonate + 1) - s.begin(), cnt = 0;
        for (int i = lim - 1; i >= 0; i--) {
            if (time_detonate >= s[i]) {
                cnt++;
                time_detonate--;
            }
        }
        cout << min(cnt, num_drop) << "\n";
    }
    return 0;
}
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
        int n, cnt = 0; cin >> n;
        vector <int> a(n);
        vector <bool> extrema(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n - 1; i++) {
            if (abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]) > abs(a[i + 1] - a[i - 1])) {
                extrema[i] = 1; cnt++;
            }
        }
        int reduce = 0;
        for (int i = 1; i < n - 1; i++) {
            int normal_cnt = 0, mod_cnt = 0, og = a[i];
            for (int j = i - 1; j < i + 2; j++) {
                if (extrema[j]) {
                    normal_cnt++;
                }
            }
            a[i] = a[i + 1];
            if (i > 1 && abs(a[i - 1] - a[i - 2]) + abs(a[i - 1] - a[i]) > abs(a[i - 2] - a[i])) {
                mod_cnt++;
            }
            reduce = max(normal_cnt - mod_cnt, reduce);
            a[i] = a[i - 1]; mod_cnt = 0;
            if (i < n - 2 && abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i + 2]) > abs(a[i + 2] - a[i])) {
                mod_cnt++;
            }
            a[i] = og;
            reduce = max(normal_cnt - mod_cnt, reduce);
        }
        cout << cnt - reduce << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
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
        int n, m, b; cin >> n >> m;
        ll sum1 = 0, sum2 = 0, pts = -1; 
        vector <ll> a(n), one, two;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b;
            if (b == 1) {
                sum1 += a[i];
                one.push_back(a[i]);
            }
            else {
                sum2 += a[i];
                two.push_back(a[i]);
            }
        }
        sort(one.begin(), one.end(), greater <ll> ());
        sort(two.begin(), two.end(), greater <ll> ());
        if (sum1 + sum2 >= m) {
            pts = one.size() + 2 * two.size();
            ll prefix_sum_1 = 0, prev_val = 0;
            for (int i = 0; i <= one.size(); i++) {
                if (i) {
                    prefix_sum_1 += one[i - 1];
                }
                while (prefix_sum_1 + sum2 >= m && !two.empty()) {
                    prev_val = two.back();
                    sum2 -= prev_val;
                    two.pop_back();
                }
                if (prefix_sum_1 + sum2 < m) {
                    sum2 += prev_val;
                    two.push_back(prev_val);
                }
                if (prefix_sum_1 + sum2 >= m) {
                    ll o = i, t = two.size();
                    pts = min(pts, o + 2 * t);
                }
            }
        }
        cout << pts << "\n";
    }
    return 0;
}

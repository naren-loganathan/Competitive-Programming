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
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1, max_p = -1;
        vector <int> b(n, 1), p(n);
        int c = mid + (l == mid);
        for (int i = 0; i < n; i++) {
            if (a[i] < c) {
                b[i] = -1;
            }
            p[i] = b[i] + (i ? p[i - 1] : 0);
        }
        vector <int> x(n + 1, 0);
        x[1] = min(p[0], 0);
        for (int i = 1; i < n; i++) {
            x[i + 1] = min(x[i], p[i]);
            if (i >= k - 1) {
                max_p = max(p[i] - x[i - k + 1], max_p);
            }
        }
        if (max_p > 0) {
            (l == mid ? l++ : l = mid);
        }
        else {
            (l == mid ? r-- : r = mid - 1);
        }
    }
    cout << l << "\n";
    return 0;
}
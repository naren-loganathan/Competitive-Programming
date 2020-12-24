#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int max_diff = (-3) * (n + m), score_a, score_b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //case1: d == 0
    if (3 * (n - m) > max_diff) {
        score_a = 3 * n;
        score_b = 3 * m;
        max_diff= 3 * (n - m);
    }
    //case2: d >= max(a[n - 1], b[m - 1])
    if (2 * (n - m) > max_diff) {
        score_a = 2 * n;
        score_b = 2 * m;
        max_diff = 2 * (n - m);
    }
    //case3: all elements of a are greater than elements of b
    if (a[0] - 1 >= b[m - 1]) {
        max_diff = 3 * n - 2 * m;
        score_a = 3 * n;
        score_b = 2 * m;
    }
    //case4: other stuff
    for (int i = 0; i < n + m; i++) {
        int d;
        if (i >= n) {
            d = b[i - n];
        }
        else {
            d = a[i];
        }
        int x = (lower_bound(a.begin(), a.end(), d + 1) - a.begin());
        int y = (lower_bound(b.begin(), b.end(), d + 1) - b.begin());
        int sa = 2 * x + 3 * (n - x);
        int sb = 2 * y + 3 * (m - y);
        if (sa - sb > max_diff) {
            max_diff = sa - sb;
            score_a = sa;
            score_b = sb;
        }
        else if (sa - sb == max_diff) {
            if (sa > score_a) {
                score_a = sa;
                score_b = sb;
            }
        }
    }
    cout << score_a << ":" << score_b << "\n";
    return 0;
}
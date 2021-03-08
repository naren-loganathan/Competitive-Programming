#include <iostream>
#include <vector>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w; cin >> n >> w;
    vector <int> a(n), b(w), a_diff(n - 1), b_diff(w - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) a_diff[i - 1] = a[i] - a[i - 1];
    }
    for (int i = 0; i < w; i++) {
        cin >> b[i];
        if (i) b_diff[i - 1] = b[i] - b[i - 1];
    }
    if (w == 1) cout << n << '\n';
    else {
        int ans = 0;
        vector <int> x, prefix(n + w);

        for (int i = 0; i < w - 1; i++) x.push_back(b_diff[i]);
        x.push_back(2e9 + 1);
        for (int i = 0; i < n - 1; i++) x.push_back(a_diff[i]);

        for (int i = 1; i < x.size(); i++) {
            int j = prefix[i - 1];
            while (j > 0 && x[i] != x[j]) j = prefix[j - 1];

            if (x[i] == x[j]) j += 1;
            prefix[i] = j;
            if (i > w && prefix[i] == w - 1) ans += 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
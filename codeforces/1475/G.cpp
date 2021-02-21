#include <iostream>
#include <vector>
#include <map>
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
        int n, result = n; cin >> n;
        vector <int> a(n), c(2e5 + 1, 0);
        map <int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; cnt[a[i]]++;
        }
        for (int i = 1; i <= 2e5; i++) {
            c[i] += cnt[i];
            for (int j = 2 * i; j <= 2e5; j += i) {
                c[j] = max(c[j], c[i]);
            }
        }
        for (int i = 1; i <= 2e5; i++) {
            result = min(result, n - c[i]);
        }
        cout << result << "\n";
    }
    return 0;
}
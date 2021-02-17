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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > 2 * a[i + 1]) {
                cnt++;
                int k = 4;
                while (a[i] > k * a[i + 1]) {
                    cnt++; k *= 2;
                }
            }
            else if (a[i + 1] > 2 * a[i]) {
                cnt++;
                int k = 4;
                while (a[i + 1] > k * a[i]) {
                    cnt++; k *= 2;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
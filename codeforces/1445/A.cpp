#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        bool possible = 1;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] += b[n - 1 - i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                possible = 0;
                break;
            }
        }
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
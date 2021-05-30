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
        cout << 3 * n << '\n';
        for (int i = 1; i <= n; i += 2) {
            cout << "1 " << i << ' ' << i + 1 << '\n';
            cout << "1 " << i << ' ' << i + 1 << '\n';
            cout << "2 " << i << ' ' << i + 1 << '\n';
            cout << "1 " << i << ' ' << i + 1 << '\n';
            cout << "1 " << i << ' ' << i + 1 << '\n';
            cout << "2 " << i << ' ' << i + 1 << '\n';
        }
    }
    return 0;
}
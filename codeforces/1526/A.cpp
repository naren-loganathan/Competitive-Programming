#include <iostream>
#include <vector>
#include <algorithm>
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
        vector <int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int x = 0, y = n;
        for (int i = 0; i < n; i++) {
            cout << a[x] << ' ' << a[y] << ' ';
            x++; y++;
        }
        cout << '\n';
    }
    return 0;
}

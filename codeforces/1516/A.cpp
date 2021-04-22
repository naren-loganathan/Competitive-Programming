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
        int n, k; cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1 && k; i++) {
            int moves = min(a[i], k);
            a[i] -= moves; a[i + 1] += moves;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
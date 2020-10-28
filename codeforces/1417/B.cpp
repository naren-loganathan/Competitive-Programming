#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, u;
        cin >> n >> u;
        vector <int> a(n), b(n);
        bool flip = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if ((a[i] <= u / 2 && u % 2) || (u % 2 == 0 && a[i] < u / 2)) {
                b[i] = 0;
            }
            else if (a[i] == u / 2 && u % 2 == 0) {
                (flip ? b[i] = 1 : b[i] = 0);
                flip = !flip;
            }
            else {
                b[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
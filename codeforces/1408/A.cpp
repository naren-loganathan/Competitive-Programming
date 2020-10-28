#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n), b(n), c(n), result(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (i != 0) {
                if (a[i] != result[i - 1]) {
                    result[i] = a[i];
                }
                else if (b[i] != result[i - 1]) {
                    result[i] = b[i];
                }
                else {
                    result[i] = c[i];
                }
            }
            else {
                result[i] = a[i];
            }
        }
        if (a[n - 1] != a[0] && a[n - 1] != result[n - 2]) {
            result[n - 1] = a[n - 1];
        }
        else if (b[n - 1] != a[0] && b[n - 1] != result[n - 2]) {
            result[n - 1] = b[n - 1];
        }
        else {
            result[n - 1] = c[n - 1];
        }
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
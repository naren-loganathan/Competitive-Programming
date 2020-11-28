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
    int n; cin >> n;
    vector <int> a(n), b(n - 1), c(n - 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 2; i++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    bool eh = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i]) {
            cout << a[i] << "\n";
            eh = 1;
            break;
        }
    }
    if (!eh) {
        cout << a[n - 1] << "\n";
    }
    eh = 0;
    for (int i = 0; i < n - 2; i++) {
        if (b[i] != c[i]) {
            cout << b[i] << "\n";
            eh = 1;
            break;
        }
    }
    if (!eh) {
        cout << b[n - 2] << "\n";
    }
    return 0;
}
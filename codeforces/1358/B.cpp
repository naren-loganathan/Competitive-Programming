#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0;
        for (i = n - 1; i >= 0; i--) {
            if (i + 1 >= a[i]) {
                break;
            }
        }
        cout << i + 2 << "\n";
    }
    return 0;
}
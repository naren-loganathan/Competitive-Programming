#include <iostream>
#include <vector>
#include <cmath>
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
        int n, colours = 1, length = 1; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                if (a[i] == a[i - 1]) {
                    length++;
                }
                else {
                    colours = max(colours, length);
                    length = 1;
                }
            }
        }
        colours = max(colours, length);
        cout << colours << "\n";
    }
    return 0;
}

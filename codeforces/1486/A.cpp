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
        bool possible = 1;
        vector <ll> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        ll rem = h[0]; h[0] = 0;
        for (int i = 1; i < n; i++) {
            h[i] += rem;
            if (h[i] < i) {
                possible = 0;
            }
            else {
                rem = h[i] - i;
                h[i] = i;
            }
        }
        for (int i = 1; i < n; i++) {
            if (h[i] <= h[i - 1]) {
                possible = 0;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
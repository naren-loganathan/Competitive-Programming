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
        int n, k; cin >> n >> k;
        vector <int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int pos = 0;
        for (int i = 1; i <= k && pos != -1; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1 && h[j + 1] > h[j]) {
                    h[j]++;
                    pos = j + 1;
                    break;
                }
                else if (j == n - 1) {
                    pos = -1;
                }
            }
        }
        cout << pos << "\n";
    }
    return 0;
}
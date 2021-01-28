#include <iostream>
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
        int n; cin >> n;
        bool possible = 0;
        for (int i = 0; i <= ceil(n / 2020); i++) {
            if ((n - 2020 * i) % 2021 == 0) {
                possible = 1;
                break;
            }
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//FFFFFFFFFFFFFFFF   Salt        Salt
//FFFFFFFFFFFFFFFF   Salt        Salt
//F                  Salt        Salt
//FFFFFFFF           Salt        Salt
//FFFFFFFF           Salt        Salt
//F                  Salt        Salt
//F                  SaltSaltSaltSalt
//F                  SaltSaltSaltSalt

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        bool possible = 1;
        int n; cin >> n;
        vector <ll> d(2 * n), gap;
        for (int i = 0; i < 2 * n; i++) {
            cin >> d[i];
        }
        sort (d.begin(), d.end());
        ll cnt = 1;
        for (int i = 1; i < 2 * n; i += 2) {
            if (d[i] != d[i - 1] || d[i] % 2 || d[i] == 0) {
                possible = 0;
                break;
            }
            if (i >= 3) {
                if ((d[i] - d[i - 2]) % (2 * cnt) || d[i] == d[i - 2]) {
                    possible = 0;
                    break;
                }
                else {
                    gap.push_back((d[i] - d[i - 2]) / (2 * cnt));
                }
                cnt++;
            }
        }
        if (possible && !gap.empty()) {
            ll sum = gap[0];
            for (int i = 1; i < gap.size(); i++) {
                gap[i] += gap[i - 1]; sum += gap[i];
            }
            if (d[0] - 2 * sum <= 0 || (d[0] - 2 * sum) % (2 * n)) {    //why is it (2 * n) instead of n?
                possible = 0;
            }
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
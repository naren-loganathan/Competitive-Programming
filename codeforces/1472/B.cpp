#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
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
        int n, sum = 0; cin >> n;
        int cnt1 = 0, cnt2 = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 1) {
                cnt1++;
            }
            else {
                cnt2++;
            }
        }
        bool possible = 1;
        if (sum % 2) {
            possible = 0;
        }
        else {
            sum /= 2;
            if (sum % 2) {
                if (cnt1 == 0) {
                    possible = 0;
                }
            }
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
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
        ll w, h, n, cnt = 1; 
        cin >> w >> h >> n;
        while (w % 2 == 0) {
            cnt *= 2;
            w /= 2;
        }
        while (h % 2 == 0) {
            cnt *= 2;
            h /= 2;
        }
        cout << (cnt >= n ? "Yes" : "No") << "\n";
    }
    return 0;
}
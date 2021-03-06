#include <iostream>
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
        int n, k, cnt = 0; 
        cin >> n >> k;
        cnt = n - k + (k / 2);
        cout << cnt << '\n';
        for (int i = k / 2 + (k % 2); i <= n; i++) {
            if (i != k) cout << i << ' ';
        }
        if (cnt) cout << '\n';
    }
    return 0;
}
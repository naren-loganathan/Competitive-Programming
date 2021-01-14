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
        ll n, k; cin >> n >> k;
        ll a_inversions = 0, diff = 1, cnt = 0;
        for (int i = k - 1; i >= k - (n - k); i--) {
            a_inversions += diff;
            cnt++;
            diff += 2;
        }
        for (int i = 1; i <= k - 1 - cnt; i++) {
            cout << i << " ";
        }
        for (int i = k; i >= k - cnt; i--) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
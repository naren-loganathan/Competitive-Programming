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
    int n, q; cin >> n >> q;
    int cnt0 = 0, cnt1 = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) cnt0++;
        else cnt1++;
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; cin >> idx;
            if (a[idx - 1] == 0) {
                a[idx - 1] = 1;
                cnt0--; cnt1++;
            }
            else {
                a[idx - 1] = 0;
                cnt1--; cnt0++;
            }
        }
        else {
            int k; cin >> k;
            if (n - k >= cnt0) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
    }
    return 0;
}
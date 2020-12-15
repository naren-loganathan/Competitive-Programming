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
        vector <int> b(n), ans;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            ans.push_back(b[l]);
            l++;
            ans.push_back(b[r]);
            r--;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
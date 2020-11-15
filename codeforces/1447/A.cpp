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
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
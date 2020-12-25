#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
        vector <int> a(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << a[0] * a[2] << "\n";
    }
    return 0;
}
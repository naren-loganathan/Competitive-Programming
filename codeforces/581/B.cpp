#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> h(n), m(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        m[i] = max(m[i + 1], h[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << max(m[i] - h[i] + 1, 0) << " ";
    }
    cout << "\n";
    return 0;
}
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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0, u = a[0], v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > u) {
            cnt++;
            u = a[i];
        }
        if (a[i] < v) {
            cnt++;
            v = a[i];
        }
    }
    cout << cnt << "\n";
    return 0;
}
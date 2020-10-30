#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater <ll> ());
        ll sum = 0, i = 0; 
        while (sum >= i * x && i < n) {
            sum += a[i];
            i++;
        }
        if (sum < i * x) {
            i--;
        }
        cout << i << "\n";
    }
    return 0;
}
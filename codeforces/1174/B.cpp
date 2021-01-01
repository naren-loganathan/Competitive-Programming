#include <iostream>
#include <vector>
#include <algorithm>
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
    bool even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            odd = 1;
        }
        else {
            even = 1;
        }
    }
    if (odd && even) {
        sort(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
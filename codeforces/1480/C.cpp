#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector <int> a(1e5 + 2, 0);

int query (int i) {
    if (a[i] == 0) {
        cout << "? " << i << endl;
        cin >> a[i];
    }
    return a[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    a[0] = 1e5 + 1, a[n + 1] = 1e5 + 1;
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (query(mid) > query(mid + 1)) {
            lo = mid + 1;
        }
        else {
            hi = mid; 
        }
    }
    cout << "! " << lo << endl;
    return 0;
}
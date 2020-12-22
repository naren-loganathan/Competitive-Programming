#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, l = 0, r = 0; cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <int> s; s.insert(a[0]);
    while (r <= n - 1 && s.size() < k) {
        if (r + 1 < n) {
            s.insert(a[r + 1]);
            while (a[r + 1] == a[l] && l < r + 1) {
                l++;
            }
        }
        r++;
    }
    if (s.size() != k) {
        l = -2; r = -2;
    }
    else {
        s.clear();
        int i = r;
        for (; i >= l; i--) {
            s.insert(a[i]);
            if (s.size() == k) {
                break;
            }
        }
        l = i;
    }
    cout <<  l + 1 << " " << r + 1 << "\n";
    return 0;
}
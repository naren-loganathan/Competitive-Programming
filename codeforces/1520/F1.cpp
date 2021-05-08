#include <iostream>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int query(int l, int r) {
    int a;
    cout << "? " << l << ' ' << r << endl;
    cin >> a;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t; cin >> n >> t;
    while (t--) {
        int k, ans; 
        cin >> k;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid == l) {
                if (mid - query(1, mid) == k) {
                    l = mid; r = mid;
                } else {
                    l = mid + 1; r = mid + 1;
                }
            } else {
                if (mid - query(1, mid) < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        cout << "! " << l << '\n'; 
    }
    return 0;
}
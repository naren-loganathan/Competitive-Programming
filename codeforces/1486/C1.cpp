#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int query (int l, int r) {
    cout << "? " << l << " " << r << endl;
    int pos; cin >> pos;
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int l = 1, r = n, p;
    bool change = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (change) {
            p = query(l, r);
        }
        if (l != mid) {
            if (p <= mid) {
                if (query(l, mid) == p)  {
                    r = mid;
                    change = 0;
                }
                else {
                    l = mid + 1;
                    change = 1;
                }
            }
            else {
                if (query(mid, r) == p)  {
                    l = mid;
                    change = 0;
                }
                else {
                    r = mid - 1;
                    change = 1;
                }
            }
        }
        else {
            if (p == l) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << "! " << l << endl;
    return 0;
}
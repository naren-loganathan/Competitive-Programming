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
    int p = query(1, n), l = 1, r = n;
    if (p == 1) {
        l = 2;
    }
    else if (p == n) {
        r = n - 1;
    }
    else {
        if (query(p, n) == p) {
            l = p + 1;
        }
        else {
            r = p - 1;
        }
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (l == mid) {
            if (r < p) {
                if (query(r, p) == p) {
                    l++;
                }
                else {
                    r--;
                }
            }
            else {
                if (query(p, l) == p) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        else {
            if (r < p) {
                if (query(mid, p) == p) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if (query(p, mid) == p) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
        }
    }
    cout << "! " << l << endl;
    return 0;
}
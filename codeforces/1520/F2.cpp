#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

class BIT {
    private:

    int n;
    vector <int> tree;

    int prefix_sum(int r) {
        int sum = 0;
        while (r >= 0) {
            sum += tree[r];
            r = (r & (r + 1)) - 1;
        }
        return sum;
    }

    void update(int i, int x) {
        while (i < n) {
            tree[i] += x;
            i = i | (i + 1);
        }
    }

    public:

    BIT(int n) {
        this -> n = n;
        tree.assign(n, 0);
    }

    void range_update(int l, int r, int x) {
        update(l, x);
        if (r < n - 1) {
            update(r + 1, -x);
        }
    }

    int point_query(int i) {
        return prefix_sum(i);
    }
};

int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int a; cin >> a;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t; cin >> n >> t;
    BIT fenwick_tree = BIT(n + 1);
    fenwick_tree.range_update(1, n, -1e6);
    while (t--) {
        int k, ans; 
        cin >> k;
        int l = 1, r = n;
        while (l < r) {
            int mid = (r + l) >> 1;
            int q = fenwick_tree.point_query(mid);
            if (q < 0) {
                int x = query(1, mid);
                fenwick_tree.range_update(mid, mid, x - q);
                q = x;
            }
            if (mid == l) {
                if (mid - q == k) {
                    l = mid; r = mid;
                } else {
                    l = mid + 1; r = mid + 1;
                }
            } else {
                if (mid - q < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        cout << "! " << l << endl;
        fenwick_tree.range_update(l, n, 1);
    }
    return 0;
}
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
    int t; cin >> t;
    while (t--) {
        int n, x, o = 0; 
        cin >> n >> x;
        vector <int> a(n);
        bool possible = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (is_sorted(a.begin(), a.end())) {
            possible = 1;
        }
        for (int i = 0; i < n && possible == 0; i++) {
            if (a[i] > x) {
                swap(a[i], x);
                o++;
            }
            if (is_sorted(a.begin(), a.end())) {
                possible = 1;
            }
        }
        if (possible) {
            cout << o << "\n";
        }
        else {
            cout << "-1" << "\n";
        }
    }
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

typedef long long int ll;
#define ub upper_bound

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, s, k, closed;
        cin >> n >> s >> k;
        set <int> a;
        for (int i = 0; i < k; i++) {
            cin >> closed;
            a.insert(closed);
        }
        int min_dist = 0;
        for (int i = 0; i < 1005; i++) {
            if (s + i <= n && a.find(s + i) == a.end()) {
                break;
            }
            if (i < s && a.find(s - i) == a.end()) {
                break;
            }
            min_dist++;
        }
        cout << min_dist << "\n";        
    }
    return 0;
}
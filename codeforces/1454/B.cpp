#include <iostream>
#include <vector>
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
        int n, p; cin >> n;
        vector < vector <int> > a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p;
            a[p].push_back(i);
        }
        int result = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i].size() == 1) {
                result = a[i][0];
                break;
            }
        }
        cout << result << "\n";
    }
    return 0;
}
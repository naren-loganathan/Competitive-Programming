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
        int n, m, a; cin >> n >> m;
        vector <int> num;
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a < 0) {
                    cnt++;
                }
                sum += (abs(a)); 
                num.push_back(abs(a));
            }
        }
        sort(num.begin(), num.end());
        if (cnt % 2) {
            sum -= 2 * num[0];
        }
        cout << sum << "\n";
    }
    return 0;
}
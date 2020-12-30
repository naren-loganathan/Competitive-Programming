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
        int n; cin >> n;
        vector <int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i < p.size() - 1; i++) {
            if (abs(p[i] - p[i - 1]) + abs(p[i] - p[i + 1]) == abs(p[i + 1] - p[i - 1])) {
                p.erase(p.begin() + i);
                i--;
            }
        }
        cout << p.size() << "\n";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
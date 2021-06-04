#include <iostream>
#include <vector>
#include <cmath>
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
        vector <int> s(4);
        for (int i = 0; i < 4; i++) {
            cin >> s[i];
        }
        int f1 = max(s[0], s[1]);
        int f2 = max(s[2], s[3]);
        sort(s.begin(), s.end());
        if (s[2] == f1 && s[3] == f2) {
            cout << "YES" << '\n';
        } else if (s[2] == f2 && s[3] == f1) {
            cout << "YES" << '\n';            
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}

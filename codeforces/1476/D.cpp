#include <iostream>
#include <string>
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
        string s; cin >> s;
        vector <int> left(n + 1, 0), right(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'R') {
                if (i < n - 1 && s[i + 1] == 'L') {
                    right[i] = right[i + 2] + 2;
                }
                else {
                    right[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                if (i && s[i - 1] == 'R') {
                    left[i + 1] = left[i - 1] + 2;
                }
                else {
                    left[i + 1] = 1;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            cout << left[i] + right[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

#include <iostream>
#include <string>
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
        string a = "1", b; cin >> b;
        for (int i = 1; i < n; i++) {
            int sum = a[i - 1] - 48 + b[i - 1] - 48;
            if (sum == 1) {
                if (b[i] == '0') {
                    a.push_back('0');
                }
                else {
                    a.push_back('1');
                }
            }
            else if (sum == 2) {
                if (b[i] == '0') {
                    a.push_back('1');
                }
                else {
                    a.push_back('0');
                }
            }
            else if (sum == 0) {
                a.push_back('1');
            }
        }
        cout << a << "\n";
    }
    return 0;
}

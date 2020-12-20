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
        int n, cnt = 0; cin >> n;
        string s; cin >> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                cnt++;
            }
            else {
                break;
            }
        }
        cout << (cnt > n - cnt ? "Yes" : "No") << "\n";
    }
    return 0;
}
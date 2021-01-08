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
        string s = "";
        int num = 57;
        if (n == 1) {
            s += "9";
        }
        if (n >= 2) {
            s += "98";
        }
        for (int i = 2; i < n; i++) {
            char c = num;
            s += c;
            if (num == 57) {
                num = 48;
            }
            else {
                num++;
            }
        }
        cout << s << "\n";
    }
    return 0;
}


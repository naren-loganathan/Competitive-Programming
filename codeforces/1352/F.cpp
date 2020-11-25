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
        string s = "";
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if (n1 == 0) {
            if (n0) {
                for (int i = 0; i <= n0; i++) {
                    s.push_back('0');
                }
            }
            if (n2) {
                for (int i = 0; i <= n2; i++) {
                    s.push_back('1');
                }
            }
        }
        else {
            for (int i = 0; i < n2; i++) {
                s.push_back('1');
            }
            for (int i = 0; i <= n1; i++) {
                s.push_back(i % 2 ? '0' : '1');
            }
            string ins = "";
            for (int i = 0; i < n0; i++) {
                    ins.push_back('0');
            }
            if (s.back() == '1') {
                s.insert(s.length() - 2, ins);
            }
            else {
                s += ins;
            }
        }
        cout << s << "\n";
    }
    return 0;
}
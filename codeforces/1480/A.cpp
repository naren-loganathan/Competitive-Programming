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
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                s[i] = (s[i] == 'a' ? 'b' : 'a');
            }
            else {
                s[i] = (s[i] == 'z' ? 'y' : 'z');
            }
        }
        cout << s << "\n";
    }
    return 0;
}

#include <iostream>
#include <stack>
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
        int moves = 0;
        string s; cin >> s;
        stack <char> c;
        for (int i = 0; i < s.length(); i++) {
            if (!c.empty() && c.top() != s[i]) {
                c.pop();
                moves++;
            }
            else {
                c.push(s[i]);
            }
        }
        cout << (moves % 2 ? "DA" : "NET") << "\n";
    }
    return 0;
}

#include <iostream>
#include <string>
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
        stack <char> op0, op1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                op0.push('(');
            }
            else if (s[i] == '[') {
                op1.push('[');
            }
            else if (s[i] == ')') {
                if (op0.empty() == 0) {
                    op0.pop(); moves++;
                }
            }
            else if (s[i] == ']') {
                if (op1.empty() == 0) {
                    op1.pop(); moves++;
                }
            }
        }
        cout << moves << "\n";
    }
    return 0;
}
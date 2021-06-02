#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t = "", u = ""; 
    cin >> s;
    int n = s.length();
    vector <char> m(n);
    m.back() = s.back();
    for (int i = n - 2; i >= 0; i--) {
        m[i] = min(s[i], m[i + 1]);
    }
    stack <char> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == m[i]) {
            u += s[i];
            if (i < n - 1) {
                while (!stk.empty() && stk.top() <= m[i + 1]) {
                    u += stk.top();
                    stk.pop();
                }
            }
        } else {
            stk.push(s[i]);
        }
    }
    while (!stk.empty()) {
        u += stk.top();
        stk.pop();
    }
    cout << u << '\n';
    return 0;
}
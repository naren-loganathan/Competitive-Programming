#include <iostream>
#include <stack>
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
        string a, r = ""; cin >> a;
        stack <char> even, odd;
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a[i] % 2 == 0) {
                even.push(a[i]);
            }
            else {
                odd.push(a[i]);
            }
        }
        while (!even.empty() || !odd.empty()) {
            if (!even.empty() && (odd.empty() || even.top() < odd.top())) {
                r += even.top();
                even.pop();
            }
            else {
                r += odd.top();
                odd.pop();
            }
        }
        cout << r << "\n";
    }
    return 0;
}
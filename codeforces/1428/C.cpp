#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;
        stack <char> letters;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                letters.push(s[i]);
            }
            if (s[i] == 'B') {
                if (letters.empty()) {
                    letters.push(s[i]);
                }
                else {
                    letters.pop();
                }
            }
        }
        cout << letters.size() << "\n";
    }
    return 0;
}
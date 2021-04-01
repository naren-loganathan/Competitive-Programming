#include <iostream>
#include <string>
#include <vector>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s; cin >> s;
    vector <int> v(s.length());
    for (int i = 0; i < s.length(); i++) {
        v[i] = (s[i] - 'A');
    }
    bool poss = 1;
    for (int i = 2; i < s.length(); i++) {
        if ((v[i - 2] + v[i - 1]) % 26 != v[i]) {
            poss = 0; break;
        }
    }
    cout << (poss ? "YES" : "NO") << '\n';
    return 0;
}
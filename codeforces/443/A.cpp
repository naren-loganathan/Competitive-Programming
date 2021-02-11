#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set <char> letters;
    string s;
    getline(cin, s);
    for (int i = 1; i < s.length(); i += 3) {
        if (s[i] != '}') {
            letters.insert(s[i]);
        }
    }
    cout << letters.size() << "\n";
    return 0;
}
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
    int n, faces = 0; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s.front() == 'I') {
            faces += 20;
        }
        else if (s.front() == 'D') {
            faces += 12;
        }
        else if (s.front() == 'O') {
            faces += 8;
        }
        else if (s.front() == 'C') {
            faces += 6;
        }
        else if (s.front() == 'T') {
            faces += 4;
        }
    }
    cout << faces << "\n";
    return 0;
}
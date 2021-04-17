#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector <char> nxt[26];
    vector <int> iter(26);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            nxt[i].push_back(char(97 + (i + j) % k));
        }
    }
    string s = "a";
    while (s.length() < n) {
        int i = s.back() - 97;
        s += nxt[i][iter[i]];
        iter[i] = (iter[i] + 1) % k;
    }
    cout << s << '\n';
    return 0;
}
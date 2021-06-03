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
    int n; cin >> n;
    string s; cin >> s;
    int cnt_W = 0, cnt_B = 0;
    for (int i = 0; i < n; i++) {
        s[i] == 'W' ? cnt_W++ : cnt_B++;
    }
    if ((n - cnt_W) % 2 && (n - cnt_B) % 2) {
        cout << -1 << '\n';
    } else {
        vector <int> moves;
        char target = ((n - cnt_W) % 2 ? 'B' : 'W');
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != target) {
                moves.push_back(i + 1);
                s[i] = (s[i] == 'W' ? 'B' : 'W');
                s[i + 1] = (s[i + 1] == 'W' ? 'B' : 'W');
            }
        }
        cout << moves.size() << '\n';
        for (int i = 0; i < moves.size(); i++) {
            cout << moves[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

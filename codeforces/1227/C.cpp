#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector < pair <int, int> > moves;
        string ans = "";
        for (int i = 0; i < k - 1; i++) ans += "()";
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; i++) ans += "(";
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; i++) ans += ")";
        for (int i = 0; i < n; i++) {
            if (s[i] != ans[i]) {
                for (int j = i + 1; j < n; j++) {
                    string s_new = s;
                    if (s[j] == ans[i]) {
                        moves.push_back(mp(i + 1, j + 1));
                        for (int k = i; k <= j; k++) {
                            s_new[k] = s[j + i - k];
                        }
                        s = s_new;
                        break;
                    }
                }
            }
        }
        cout << moves.size() << '\n';
        for (int i = 0; i < moves.size(); i++) {
            cout << moves[i].fi << ' ' << moves[i].se << '\n';
        }
    }
    return 0;
}
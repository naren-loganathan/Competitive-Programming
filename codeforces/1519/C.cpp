#include <iostream>
#include <vector>
#include <algorithm>
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
        ll n; cin >> n;
        vector <ll> u(n), s(n);
        vector < vector <ll> > team(n);
        for (int i = 0; i < n; i++) {
            cin >> u[i]; u[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            team[u[i]].push_back(s[i]);
        }
        for (int i = 0; i < n; i++) {
            sort(team[i].begin(), team[i].end(), greater <ll> ());
        }
        vector <ll> total_skill(n + 1);
        for (int i = 0; i < n; i++) {
            int len = team[i].size();
            for (int j = 1; j < len; j++) {
                team[i][j] += team[i][j - 1];
            }
            for (int j = 1; j <= len; j++) {
                total_skill[j] += team[i][len - 1 - (len % j)];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << total_skill[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
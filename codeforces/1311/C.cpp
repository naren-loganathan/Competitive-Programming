#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m; 
        cin >> n >> m;
        string s; cin >> s;
        vector < vector <int> > l(n + 1, vector <int> (26, 0));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                l[i + 1][s[i] - 97]++;
            }
            else {
                l[i + 1] = l[i];
                l[i + 1][s[i] - 97]++;
            }
        }
        vector <int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        vector <int> freq(26, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                freq[j] += l[p[i]][j];
            }
        }
        for (int i = 0; i < 26; i++) {
            freq[i] += l[n][i];
            cout << freq[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
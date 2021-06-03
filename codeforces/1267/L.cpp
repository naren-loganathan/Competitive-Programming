#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, k; 
    cin >> n >> l >> k;
    string s; cin >> s;
    vector <string> v(n);
    sort(s.begin(), s.end());
    int cur = 0, st = 0;
    while ((int) v[k - 1].length() < l) {
        for (int i = st; i < k; i++) {
            v[i] += s[cur++];
        }
        int x = k - 1;
        while (x - 1 >= 0 && v[x - 1].back() == v[k - 1].back()) {
            x--;
        }
        st = x;
    }
    while (cur < s.length()) {
        for (int i = 0; i < n; i++) {
            if (v[i].length() < l) {
                v[i] += s[cur++];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
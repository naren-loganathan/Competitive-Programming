#include <iostream>
#include <string>
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
    int k; cin >> k;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.length();
    vector <int> tree(n + 1);
    for (int i = n; i > n - (1 << (k - 1)); i--) {
        tree[i] = (s[i - 1] == '?' ? 2 : 1);
    }
    for (int i = n - (1 << (k - 1)); i > 0; i--) {
        if (s[i - 1] == '?') {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        } else if (s[i - 1] == '0') {
            tree[i] = tree[2 * i + 1];
        } else {
            tree[i] = tree[2 * i];
        }
    }
    int q; cin >> q;
    while (q--) {
        int p; char c; 
        cin >> p >> c;
        s[n - p] = c;
        int i = n - p + 1;
        while (i > 0) {
            if (i > n - (1 << (k - 1))) {
                tree[i] = (s[i - 1] == '?' ? 2 : 1);
            } else {
                if (s[i - 1] == '?') {
                    tree[i] = tree[2 * i] + tree[2 * i + 1];
                } else if (s[i - 1] == '0') {
                    tree[i] = tree[2 * i + 1];
                } else {
                    tree[i] = tree[2 * i];
                }
            }
            i /= 2;
        }
        cout << tree[1] << '\n';
    }
    return 0;
}
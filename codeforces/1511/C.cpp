#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector <int> colors[55], t(q);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        colors[a].push_back(i + 1);
    }
    for (int i = 0; i < q; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < q; i++) {
        int idx = colors[t[i]][0];
        cout << idx << ' ';
        for (int j = 1; j <= 50; j++) {
            int k = 0;
            while (k < colors[j].size() && colors[j][k] < idx) {
                colors[j][k]++;
                k++;
            }
        }
        colors[t[i]][0] = 1;
    }
    cout << '\n';
    return 0;
}
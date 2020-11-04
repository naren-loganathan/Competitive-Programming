#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a; cin >> n;
    vector <int> l(100005, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        l[a]++;
    }
    int q; cin >> q;
    char c;
    int cnt2 = 0, cnt4 = 0, cnt6 = 0, cnt8 = 0;
    for (int i = 0; i < 100005; i++) {
        if (l[i] >= 2) {
            cnt2++;
        }
        if (l[i] >= 4) {
            cnt4++;
        }
        if (l[i] >= 6) {
            cnt6++;
        }
        if (l[i] >= 8) {
            cnt8++;
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> c >> a;
        if (c == '+') {
            l[a]++;
            if (l[a] == 2) {
                cnt2++;
            }
            if (l[a] == 4) {
                cnt4++;
            }
            if (l[a] == 6) {
                cnt6++;
            }
            if (l[a] == 8) {
                cnt8++;
            }
        }
        else {
            if (l[a] == 2) {
                cnt2--;
            }
            if (l[a] == 4) {
                cnt4--;
            }
            if (l[a] == 6) {
                cnt6--;
            }
            if (l[a] == 8) {
                cnt8--;
            }
            l[a]--;
        }
        bool possible = 0;
        if (cnt8) {
            possible = 1;
        }
        if (cnt4 >= 2) {
            possible = 1;
        }
        if (cnt6 && cnt2 > 1) {
            possible = 1;
        }
        if (cnt4 && cnt2 > 2) {
            possible = 1;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
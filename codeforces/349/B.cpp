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
    vector <int> a(10, 1e5 + 1);
    int v; cin >> v;
    bool possible = 0;
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
        if (a[i] <= v) {
            possible = 1;
        }
    }
    if (possible) {
        int bleh = *min_element(a.begin(), a.end());
        int easy_digit = (min_element(a.begin(), a.end()) - a.begin());
        int num_digits = v / bleh; v %= bleh;
        string s;
        for (int i = 0; i < num_digits; i++) {
            s.push_back(48 + easy_digit);
        }
        int i = 0;
        while (v >= 0) {
            if (i >= s.length()) {
                break;
            }
            bool change = 0;
            for (int j = 9; j > easy_digit; j--) {
                if (a[j] - a[easy_digit] <= v) {
                    s[i] = 48 + j;
                    change = 1;
                    v -= (a[j] - a[easy_digit]);
                    break;
                }
            }
            if (change) {
                i++;
            }
            else {
                break;
            }
        }
        cout << s << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
    return 0;
}
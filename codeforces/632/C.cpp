#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

bool lambda (string s1, string s2) {
    string a = s1 + s2;
    string b = s2 + s1;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < b[i]) {
            return 1;
        }
        if (a[i] > b[i]) {
            return 0;
        }
    }
    return 0;
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), lambda);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
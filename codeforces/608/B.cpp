#include <iostream>
#include <vector>
#include <string>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll result = 0;
    string a, b;
    cin >> a >> b;
    vector <ll> prefix(a.length()), suffix(a.length());
    prefix[0] = a[0] - 48;
    suffix[a.length() - 1] = a[a.length() - 1] - 48;
    for (int i = 1; i < a.length(); i++) {
        (a[i] == '0' ? prefix[i] = prefix[i - 1] : prefix[i] = prefix[i - 1] + (ll)1);
    }
    for (int i = a.length() - 2; i >= 0; i--) {
        (a[i] == '0' ? suffix[i] = suffix[i + 1] : suffix[i] = suffix[i + 1] + (ll)1);
    }
    for (int i = 0; i < b.length(); i++) {
        if (i < a.length() && i < b.length() - a.length()) {
            if (b[i] == '0') {
                result += prefix[i];
            }
            else {
                result += (ll) (i + 1) - prefix[i];
            }
        }
        else if (i >= a.length() && i >= b.length() - a.length()) {
            int j = a.length() - (b.length() - i);
            if (b[i] == '0') {
                result += suffix[j];
            }
            else {
                result += (ll) (a.length() - j) - suffix[j];
            }
        }
        else if (i >= a.length() && i < b.length() - a.length()) {
            if (b[i] == '0') {
                result += prefix.back();
            }
            else {
                result += ((ll)a.length() - prefix.back());
            }
        }
        else {
            int j = a.length() - (b.length() - i);
            if (b[i] == '0') {
                result -= (prefix.back() - suffix[j] - prefix[i]);
            }
            else {
                result -= ((a.length() - prefix.back()) - ((ll) (a.length() - j) - suffix[j]) - ((ll) (i + 1) - prefix[i]));
            }
        }
    }
    cout << result << "\n";
    return 0;
}
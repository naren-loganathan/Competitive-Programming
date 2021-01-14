#include <iostream>
#include <string>
#include <cmath>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while (q--) {
        bool possible = 1;
        string s, t; cin >> s >> t;
        int lcm_length = s.length() * t.length() / gcd(max(s.length(), t.length()), min(s.length(), t.length()));
        string a = "", b = "";
        for (int i = 0; i < lcm_length / s.length(); i++) {
            a += s;
        }
        for (int i = 0; i < lcm_length / t.length(); i++) {
            b += t;
        }
        for (int i = 0; i < lcm_length; i++) {
            if (a[i] != b[i]) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            cout << a << "\n";
        }
        else {
            cout << "-1" << "\n";
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int decimal_index = -1; 
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            decimal_index = i; break;
        }
    }
    string a = "";
    int b = 0;
    if (decimal_index == -1) {
        int i = 0, j = (int) s.length() - 1;
        while (s[i] == '0') {
            i++;
        }
        b = j - i;
        while (s[j] == '0') {
            j--;
        }
        a = s[i];
        if (i != j) {
            a += '.' + s.substr(i + 1, j - i); 
        }
    } else {
        int i = 0, j = (int) s.length() - 1;
        while (s[i] == '0' || s[i] == '.') {
            i++;
        }
        b = decimal_index - i - (i < decimal_index ? 1 : 0);
        while (s[j] == '0' || s[j] == '.') {
            j--;
        }
        a = s[i];
        if (i != j) {
            a += '.';
            for (int k = i + 1; k <= j; k++) {
                if (s[k] != '.') {
                    a += s[k];
                }
            }
        }
    }
    cout << a;
    if (b) {
        cout << 'E' << b << '\n';
    } else {
        cout << '\n';
    }
    return 0;
}
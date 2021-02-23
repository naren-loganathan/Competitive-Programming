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
    int a, b, k; cin >> a >> b >> k;
    bool possible = 1;
    string x = "1", y = "1";
    for (int i = 1; i < a + b; i++) {
        x += "0"; y += "0";
    }
    for (int i = 2; i <= b; i++) {
        x[i - 1] = '1';
        if (i != b) y[i - 1] = '1'; 
    }
    if ((b == 1 && k != 0) || (a == 0 && k != 0)) {
        possible = 0;
    }
    else {
        if (k <= a) y[b - 1 + k] = '1';
        else {
            if (k > a + b - 2) possible = 0;
            else {
                y[b - 1] = '1';
                y.back() = '1';
                y[b - 1 - (k - a)] = '0';
            }
        }
    }
    if (possible) {
        cout << "Yes" << "\n" << x << "\n" << y << "\n";
    }
    else {
        cout << "No" << "\n";
    }
    return 0;
}
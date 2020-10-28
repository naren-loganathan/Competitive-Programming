#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a; cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '0') {
            a.erase(i, 1);
            break;
        }
        if (i == a.length() - 1) {
            a.erase(i, 1);
        }
    }
    cout << a << "\n";
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l[10] = {}, length;
    for (int i = 0; i < 6; i++) {
        cin >> length;
        l[length]++;
    }
    bool alien = 1;
    for (int i = 1; i < 10; i++) {
        if (l[i] > 3) {
            alien = 0;
            l[i] -= 4;
            break;
        }
    }
    if (alien) {
        cout << "Alien" << "\n";
    }
    else {
        for (int i = 1; i < 10; i++) {
            if (l[i] == 2) {
                cout << "Elephant" << "\n";
                break;
            }
            if (l[i] == 1) {
                cout << "Bear" << "\n";
                break;
            }
        }
    }
    return 0;
}
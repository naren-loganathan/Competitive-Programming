#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, res = 0; cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i <= n / 2; i++) {   //distance moved up
            for (int j = 0; j <= n / 2; j++) {   //distance moved right
                if ((n / 2 - i) % 2 == 0 && (n / 2 - j) % 2 == 0) {
                    if (i == 0 && j == 0) {
                        res++;
                    }
                    else if (i == 0 || j == 0) {
                        res += 2;
                    }
                    else {
                        res += 4;
                    }
                }
            }
        }
    }
    else {
        for (int i = 0; i <= n / 2 + 1; i++) {
            for (int j = 0; j <= n / 2 + 1; j++) {
                if (((n / 2 + 1 - i) % 2 == 0 && (n / 2 - j) % 2 == 0) || ((n / 2 - i) % 2 == 0 && (n / 2 + 1 - j) % 2 == 0)) {
                    if (i == 0 && j == 0) {
                        res++;
                    }
                    else if (i == 0 || j == 0) {
                        res += 2;
                    }
                    else {
                        res += 4;
                    }
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}
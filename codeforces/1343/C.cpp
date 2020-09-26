#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll max, sum = 0;
        int n, a; cin >> n;
        bool pos = 0;
        cin >> a;
        if (a > 0) {
            pos = 1;
        }
        max = a;
        for (int i = 1; i < n; i++) {
            cin >> a;
            if (a > 0) {
                if (pos == 0) {
                    pos = 1;
                    sum += max;
                    max = a;
                }
                else {
                    if (a > max) {
                        max = a;
                    }
                }
            }
            else {
                if (pos == 1) {
                    pos = 0;
                    sum += max;
                    max = a;
                }
                else {
                    if (a > max) {
                        max = a;
                    }
                }
            }
        }
        sum += max;
        cout << sum << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 2) {
            cout << "0";
        }
        else if (n % 2 == 0) {
            for (int i = 1; i < n; i++) {
                int cnt = 0;
                for (int j = i + 1; j <= n; j++) {
                    if (j == i + n / 2) {
                        cout << "0" << " ";
                    }
                    else if (cnt == (n - 2) / 2) {
                        cout << "-1" << " ";
                    }
                    else {
                        cout << "1" << " ";
                        cnt++;
                    }
                }
            }
        }
        else {
            for (int i = 1; i < n; i++) {
                int cnt = 0;
                for (int j = i + 1; j <= n; j++) {
                    if (cnt == n / 2) {
                        cout << "-1" << " ";
                    }
                    else {
                        cout << "1" << " ";
                        cnt++;
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
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
        if (n < 4) {
            cout << "-1" << "\n";
        }
        else {
            int i = 1; vector <int> b;
            if (n == 4) {
                b.push_back(3);
                b.push_back(1);
                b.push_back(4);
                b.push_back(2);
            }
            else {
                for (; i <= n; i += 2) {
                    b.push_back(i);  
                }
                i -= 5;
                b.push_back(i);
                if (n % 2) {
                    i += 2;
                    b.push_back(i);
                    i -= 4;
                }
                else {
                    i += 4;
                    b.push_back(i);
                    i -= 2;
                    b.push_back(i);
                    i -= 4;
                }
                for (; i > 0; i -= 2) {
                    b.push_back(i);
                }
            }
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
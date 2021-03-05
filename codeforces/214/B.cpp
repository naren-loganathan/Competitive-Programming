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
    int n; cin >> n;
    vector <int> digits(10, 0);
    for (int i = 0; i < n; i++) {
        int d; cin >> d; 
        digits[d] += 1;
    }
    if (digits[0] == 0) cout << -1 << '\n';
    else {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += i * digits[i];
        }
        if (sum % 3 == 1) {
            if (digits[1]) digits[1] -= 1;
            else if (digits[4]) digits[4] -= 1;
            else if (digits[7]) digits[7] -= 1;
            else {
                int cnt = 0;
                for (int i = 2; i < 10 && cnt < 2; i += 3) {
                    while (digits[i] && cnt < 2) {
                        digits[i] -= 1;
                        cnt += 1;
                    }
                }
            }
        }
        else if (sum % 3 == 2) {
            if (digits[2]) digits[2] -= 1;
            else if (digits[5]) digits[5] -= 1;
            else if (digits[8]) digits[8] -= 1;
            else {
                int cnt = 0;
                for (int i = 1; i < 10 && cnt < 2; i += 3) {
                    while (digits[i] && cnt < 2) {
                        digits[i] -= 1;
                        cnt += 1;
                    }
                }
            }
        }
        string s;
        for (int i = 9; i >= 0; i--) {
            if (s.empty() && i == 0) s = "0";
            else {
                while (digits[i]) {
                    s.push_back(('0' + i));
                    digits[i] -= 1;
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}
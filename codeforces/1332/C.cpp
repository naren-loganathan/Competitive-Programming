#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        int n, k, convert = 0; cin >> n >> k;
        string s; cin >> s;
        for (int i = 0; i < k / 2; i++) {
            vector <int> freq(26, 0);
            for (int j = 0; i + j < n; j += k) {
                freq[s[i + j] - 'a']++;
                freq[s[j + k - 1 - i] - 'a']++;
            }
            convert += (2 * n) / k - *max_element(freq.begin(), freq.end());
        }
        if (k % 2) {
            vector <int> freq(26, 0);
            for (int i = k / 2; i < n; i += k) {
                freq[s[i] - 'a']++;
            }
            convert += n / k - *max_element(freq.begin(), freq.end());
        }
        cout << convert << "\n";
    }
    return 0;
}

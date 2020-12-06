#include <iostream>
#include <string>
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
        string a, b = ""; 
        cin >> a;
        vector <int> freq(26, 0);
        for (int i = 0; i < a.length(); i++) {
            freq[a[i] - 97]++;
        }
        for (int i = 25; i >= 0; i--) {
            char c = i + 97;
            while (freq[i]--) {
                b.push_back(c);
            }
        }
        cout << b << "\n";
    }
    return 0;
}
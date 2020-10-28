#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, k, score = 0; 
        cin >> n >> k;
        string s; cin >> s;
        vector <int> wins;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == 'W') {
                    wins.push_back(i);
                    score++;
                }
            }
            else {
                if (s[i] == 'W') {
                    wins.push_back(i);
                    score++;
                    if (s[i - 1] == 'W') {
                        score++;
                    }
                }
            }
        }
        vector <int> win_d;
        for (int i = 1; i < wins.size(); i++) {
            if (wins[i] - wins[i - 1] - 1)
            win_d.push_back(wins[i] - wins[i - 1] - 1);
        }
        sort(win_d.begin(), win_d.end(), greater <int> ());
        while (k && win_d.size()) {
            if (k >= win_d.back()) {
                k -= win_d.back();
                score += 2 * (win_d.back());
                score++;
                win_d.pop_back();
            }
            else {
                score += 2 * k;
                k = 0;
            }
        }
        if (k && win_d.size() == 0) {
            int i = 0;
            while (s[i] != 'W' && i < n) {
                i++;
            }
            if (i == n) {
                score += min(2 * i - 1, 2 * k - 1);
            }
            else {
                score += min(2 * i, 2 * k);
            }
            k -= min(i, k);
        }
        if (k && win_d.size() == 0) {
            int i = n - 1;
            while (s[i] != 'W') {
                i--;;
            }
            score += min(2 * (n - 1 - i), 2 * k);
            k -= min((n - 1 - i), k);
        }
        cout << score << "\n";
    }
    return 0;
}
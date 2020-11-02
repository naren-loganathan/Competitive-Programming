#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int begin = 0, end = s.length() - 1;
        while (s[begin] == '0') {
            begin++;
            if (begin == s.length()) {
                break;
            }
        }
        if (begin == s.length()) {
            cout << "0\n";
            continue;
        }
        else {
            while (s[end] == '0') {
                end--;
            }
            while (s[begin] == '1') {
                begin++;
                if (begin == s.length()) {
                    break;
                }
            }
            while (s[end] == '1') {
                end--;
                if (end == -1) {
                    break;
                }
            }
            begin--;
            end++;
            if (begin >= end) {
                cout << a << "\n";
                continue;
            }
            else {
                vector <int> intervals;
                int length = 0;
                for (int i = begin; i <= end; i++) {
                    if (s[i] == '0') {
                        length++;
                    }
                    else {
                        if (length != 0) {
                            intervals.push_back(length);
                        }
                        length = 0;
                    }
                }
                sort(intervals.begin(), intervals.end());
                int cost = a * (intervals.size() + 1);
                for (int i = 0; i < intervals.size(); i++) {
                    int payback = intervals[i] * b - a;
                    if (payback < 0) {
                        cost += payback;
                    }
                    else {
                        break;
                    }
                }
                cout << cost << "\n";
            }
        }

    }
    return 0;
}
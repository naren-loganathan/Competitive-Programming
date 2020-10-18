#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        string s, t = "abacaba"; 
        cin >> s;
        vector <int> question_marks, m;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                question_marks.push_back(i);
            }
        }
        int w = 0, c = 0;
        for (int i = 0; i < s.length() - 6; i++) {
            bool can_form = 1, will_form = 1;
            for (int j = 0; j < 7; j++) {
                if (s[i + j] != t[j]) {
                    will_form = 0;
                    if (s[i + j] != '?') {
                        can_form = 0;
                    }
                }
            }
            if (will_form) {
                can_form = 0;
            }
            if (can_form) {
                m.push_back(i);
            }
            w += will_form;
            c += can_form;
        }
        if ((w > 1) || (w == 0 && c == 0)) {
            cout << "No\n";
        }
        else {
            bool possible = 0;
            if (w == 0) {
                for (int k = 0; k < m.size(); k++) {
                    for (int j = 0; j < 7; j++) {
                        s[m[k] + j] = t[j];
                    }
                    for (int i = 0; i < s.length(); i++) {
                        if (s[i] == '?') {
                            s[i] = 'x';
                        }
                    }
                    int count = 0;
                    for (int i = 0; i < s.length() - 6; i++) {
                        if (s.substr(i, 7) == "abacaba") {
                            count++;
                        }
                    }
                    if (count == 1) {
                        possible = 1;
                        break;
                    }
                    else {
                        for (int i = 0; i < question_marks.size(); i++) {
                            s[question_marks[i]] = '?';
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < question_marks.size(); i++) {
                    s[question_marks[i]] = 'x';
                }
                possible = 1;
            }
            if (possible) {
                cout << "Yes\n" << s << "\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
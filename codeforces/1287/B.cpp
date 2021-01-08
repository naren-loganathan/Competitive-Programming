#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
         
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
         
//S -> 83, E -> 69, T -> 84

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, cnt = 0; 
    cin >> n >> k;
    vector <string> cards(n);
    set <string> card_set;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        card_set.insert(cards[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string req = "";
            for (int idx = 0; idx < k; idx++) {
                if (cards[i][idx] == cards[j][idx]) {
                    req += cards[i][idx];
                }
                else {
                    string curr = "";
                    curr += cards[i][idx];
                    curr += cards[j][idx];
                    sort (curr.begin(), curr.end());
                    if (curr == "ST") {
                        req += "E";
                    }
                    else if (curr == "ET") {
                        req += "S";
                    }
                    else {
                        req += "T";
                    }
                }
            }
            if (card_set.find(req) != card_set.end()) {
                cnt++;
            }
        }
    }
    cout << cnt / 3 << "\n";
    return 0;
}


#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    unordered_map <string, vector < pair <int, int> > > scores;
    for (int i = 0; i < n; i++) {
        string s; int pts;
        cin >> s >> pts;
        if (scores.find(s) != scores.end()) {
            scores[s].push_back(mp(scores[s].back().fi + pts, i));
        }
        else {
            vector < pair <int, int> > history;
            scores.insert(mp(s, history));
            scores[s].push_back(mp(pts, i));
        }
    }
    int max_scores = 0, time = 0;
    string winner = "";
    for (auto itr = scores.begin(); itr != scores.end(); itr++) {
        string c = itr -> first;
        if (scores[c].back().fi > max_scores) {
            max_scores = scores[c].back().fi;
            winner = c;
            for (int i = 0; i < scores[c].size(); i++) {
                if (scores[c][i].fi >= max_scores) {
                    time = scores[c][i].se;
                    break;
                }
            }
        }
        if (scores[c].back().fi == max_scores) {
            for (int i = 0; i < scores[c].size(); i++) {
                if (scores[c][i].se > time) {
                    break;
                }
                if (scores[c][i].fi >= max_scores) {
                    time = scores[c][i].se;
                    winner = c;
                    break;
                }
            }
        }
    }
    cout << winner << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string c1, c2, diamove, regmove;
    vector <string> moves;
    cin >> c1 >> c2;
    int hor = c2[0] - c1[0], ver = c2[1] - c1[1];
    int diag = min(abs(hor), abs(ver));
    if (hor > 0) {
        diamove = (ver > 0 ? "RU" : "RD");
    }
    else {
        diamove = (ver > 0 ? "LU" : "LD");
    }
    for (int i = 0; i < diag; i++) {
        moves.push_back(diamove);
        if (diamove[0] == 'R') {
            c1[0]++;
        }
        else {
            c1[0]--;
        }
        if (diamove[1] == 'U') {
            c1[1]++;
        }
        else {
            c1[1]--;
        }
    }
    hor = c2[0] - c1[0];
    ver = c2[1] - c1[1];
    int lim = 0;
    if (ver) {
        lim = abs(ver);
        regmove = (ver > 0 ? "U" : "D");
    }
    if (hor) {
        lim = abs(hor);
        regmove = (hor > 0 ? "R" : "L");
    }
    for (int i = 0; i < lim; i++) {
        moves.push_back(regmove);
    }
    cout << moves.size() << "\n";
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << "\n";
    }

    return 0;
}
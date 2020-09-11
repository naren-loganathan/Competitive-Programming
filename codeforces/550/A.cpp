#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    vector < pair<int, int> > ab, ba;
    bool yes = 0;
    cin >> s;
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == 'A' && s[i + 1] == 'B')
            ab.push_back(make_pair(i, i + 1));
        if(s[i] == 'B' && s[i + 1] == 'A')
            ba.push_back(make_pair(i, i + 1));
    }
    if(ab.size() && ba.size()){
        for(int i = 0; i < ab.size(); i++){
            for(int j = 0; j < ba.size(); j++){
                if(ab[i].second < ba[j].first || ba[j].second < ab[i].first){
                    yes = 1;
                    break;
                }
            }
            if(yes)
                break;
        }
    }
    if(yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
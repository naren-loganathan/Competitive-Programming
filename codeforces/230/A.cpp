#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, n, x, y;
    bool progress = 1;
    vector < pair<int, int> > dragons;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        dragons.push_back(make_pair(x, y));
    }
    sort(dragons.begin(), dragons.end());
    for(int i = 0; i < dragons.size(); i++){
        if(s > dragons[i].first)
            s += dragons[i].second;
        else{
            progress = 0;
            break;
        }
    }
    if(progress)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
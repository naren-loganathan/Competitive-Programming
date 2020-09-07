#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, f, number = 1001;
    vector <int> pieces;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> f;
        pieces.push_back(f);
    }
    sort(pieces.begin(), pieces.end());
    for(int i = 0; i <= m - n; i++){
        if(number > (pieces[i + n - 1] - pieces[i]))
            number = pieces[i + n - 1] - pieces[i];
    }
    cout << number << endl;
    return 0;
}
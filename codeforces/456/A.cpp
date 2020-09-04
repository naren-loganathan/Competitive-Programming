#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    vector < pair<int, int> > laptops;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        laptops.push_back(make_pair(a, b));
    }    
        sort(laptops.begin(), laptops.end());
    for(int i = 1; i < n; i++){
        if(laptops[i].second < laptops[i - 1].second){
            cout << "Happy Alex" << "\n";
            return 0;
        }
    }
    cout << "Poor Alex" << "\n";
    return 0;
}
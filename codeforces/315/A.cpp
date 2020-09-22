#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, openable = 0;
    cin >> n;
    vector < pair<int, int> > bottles(n);
    for(int i = 0; i < n; i++){
         cin >> a >> b;
         bottles[i] = make_pair(a, b);
    }
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(bottles[j].second == bottles[i].first && i != j){
                count++;
            }
        }
        if(count != 0){
            openable++;
        }
    }
    cout << n - openable << endl;
    return 0;
}
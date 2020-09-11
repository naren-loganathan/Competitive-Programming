#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h, k, num_fallen = 2;
    vector < pair <ll, ll> > trees;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h >> k;
        trees.push_back(make_pair(h, k));
    }
    for(int i = 1; i < n - 1; i++){
        if(trees[i].first - trees[i].second > trees[i - 1].first)
            num_fallen++;
        else if(trees[i].first + trees[i].second < trees[i + 1].first){
            num_fallen++;
            trees[i].first += trees[i].second; 
        }
    }
    if(n < 2)
        cout << n << endl;
    else
        cout << num_fallen << endl;
    return 0;
}
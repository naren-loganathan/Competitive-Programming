#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, levels, a;
    bool possible = 1;
    vector <int> little_x, little_y;
    cin >> n >> levels;
    for(int i = 0; i < levels; i++){
        cin >> a;
        little_x.push_back(a);
    }
    sort(little_x.begin(), little_x.end());
    cin >> levels;
    for(int i = 0; i < levels; i++){
        cin >> a;
        little_y.push_back(a);
    }
    sort(little_y.begin(), little_y.end());
    for(int i = n; i > 0; i--){
        bool size_x = (little_x.size() == 0);
        bool size_y = (little_y.size() == 0);
        if(!size_x && !size_y){ 
            bool x = (little_x[little_x.size() - 1] == i);
            bool y = (little_y[little_y.size() - 1] == i);
            if(x && !y)
                little_x.pop_back();
            else if(y && !x)
                little_y.pop_back();
            else if(x && y){
                little_x.pop_back();
                little_y.pop_back();
            }
            else{
                possible = 0;
                break;
            }
        }
        else if(size_x && !size_y){
            bool y = (little_y[little_y.size() - 1] == i);
            if(y)
                little_y.pop_back();
            else{
                possible = 0;
                break;
            }
        }
        else if(!size_x && size_y){
            bool x = (little_x[little_x.size() - 1] == i);
            if(x)
                little_x.pop_back();
            else{
                possible = 0;
                break;
            }
        }
        else{
            possible = 0;
            break;
        }   
    }
    if(possible)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    return 0;
}
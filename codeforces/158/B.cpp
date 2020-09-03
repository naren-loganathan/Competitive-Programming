#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, min = 0, group_sizes[5] = {0, 0, 0, 0, 0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        group_sizes[s]++;
    }
    min += group_sizes[4];
    min += group_sizes[3];
    if(group_sizes[3] > group_sizes[1]){
        min += group_sizes[2] / 2;
        if(group_sizes[2] % 2 != 0)
            min++;
    }
    else{
        group_sizes[1] -= group_sizes[3];
        min += group_sizes[2] / 2;
        if(group_sizes[2] % 2 != 0){
            min++;
            if(group_sizes[1] <= 2)
                group_sizes[1] = 0;
            else
                group_sizes[1] -= 2;
            min += group_sizes[1] / 4;
            if(group_sizes[1] % 4 != 0)
                min++;
        }
        else{
            min += group_sizes[1] / 4;
            if(group_sizes[1] % 4 != 0)
                min++;
        }
    }
    cout << min << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, max_diff = -1, max = -1, ones_count, zeroes_count, lb, ub;
    vector <int> list;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        list.push_back(a);
    }
    for(int i = 0; i < n; i++){
        ones_count = 0;
        zeroes_count = 0;
        for(int j = i; j < n; j++){
            if(list[j] == 1)
                ones_count++;
            else
                zeroes_count++;
            if(zeroes_count - ones_count > max_diff){
                max = j - i + 1 - ones_count;
                max_diff = zeroes_count - ones_count;
                lb = i;
                ub = j;
            }
        }
    }
    if(max != -1){
        for(int i = 0; i < lb; i++){
            if(list[i] == 1)
                max++;
        }
        for(int i = ub + 1; i < n; i++){
            if(list[i] == 1)
                max++;
        }
    }
    else
        max = n - 1;
    cout << max << endl;
    return 0;
}
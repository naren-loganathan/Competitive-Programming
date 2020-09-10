#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, h, index = 1, sum = 0, min_sum;
    vector <int> fences;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> h;
        fences.push_back(h);
    }  
    for(int i = 0; i < k; i++)
        sum += fences[i];
    min_sum = sum;
    for(int i = 1; i <= n - k; i++){
        sum += fences[i + k - 1] - fences[i - 1];
        if(sum < min_sum){
            min_sum = sum;
            index = i + 1;
        }
    }
    cout << index << endl;
    return 0;
}
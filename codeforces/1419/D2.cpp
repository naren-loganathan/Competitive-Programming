#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> spheres(n), reordered(n);
    for(int i = 0; i < n; i++){
        cin >> spheres[i];
    }
    sort(spheres.begin(), spheres.end());
    int j = 0;
    for(int i = 1; i < n; i += 2){
        reordered[i] = spheres[j];
        j++;
    }
    for(int i = 0; i < n; i += 2){
        reordered[i] = spheres[j];
        j++;
    }
    int count = 0;
    for(int i = 1; i < n - 1; i++){
        if(reordered[i] < reordered[i - 1] && reordered[i + 1] > reordered[i]){
            count++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < n; i++){
        cout << reordered[i] << " ";
    }
    cout << endl;
    return 0;
}
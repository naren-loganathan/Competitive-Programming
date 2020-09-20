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
    int count = 0;
    for(int i = 1; i < n; i += 2){
        reordered[i] = spheres[j];
        count++;
        j++;
    }
    for(int i = 0; i < n; i += 2){
        reordered[i] = spheres[j];
        j++;
    }
    if(n <= 2){
        count = 0;
    }
    else if(n % 2 == 0){
        count--;
    }
    cout << count << endl;
    for(int i = 0; i < n; i++){
        cout << reordered[i] << " ";
    }
    cout << endl;
    return 0;
}
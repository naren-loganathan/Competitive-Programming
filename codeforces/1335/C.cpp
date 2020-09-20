#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> skills(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a;
            skills[a]++;
        }
        int max = 0, count = 0;        
        for(int i = 0; i <= n; i++){
            if(skills[i] != 0)
                count++;
            if(max < skills[i])
                max = skills[i];
        }
        if(count < 1){
            cout << "0\n";
        }
        else if(count == 1){
            if(max > 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else{
            if(count < max)
                cout << count << "\n";
            else if(count == max)
                cout << max - 1 << "\n";
            else
                cout << max << "\n";
        }
    }
    return 0;
}
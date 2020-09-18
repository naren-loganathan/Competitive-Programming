#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        int l_count = INT_MAX, r_count = INT_MAX;
        vector <int> vl(s.length(), 0), vr(s.length(), 0);
        for(int i = 0; i <= s.length(); i++){
            if(i > 0)
                vl[i - 1] = 1;
            int temp = 0;
            for(int j = 0; j < s.length(); j++){
                if(vl[j] != (s[j] - 48))
                    temp++;
            }
            if(l_count > temp)
                l_count = temp;
        }
        for(int i = 0; i <= s.length(); i++){
            if(i > 0)
                vr[s.length() - i] = 1;
            int temp = 0;
            for(int j = 0; j < s.length(); j++){
                if(vr[j] != (s[j] - 48))
                    temp++;
            }
            if(r_count > temp)
                r_count = temp;
        }
        cout << min(l_count, r_count) << "\n";
    }
    return 0;
}
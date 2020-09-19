#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, s, sum;
    cin >> m >> s;
    vector <int> digits(m);
    if(9 * m >= s && !(s == 0 && m > 1)){
        if(s == 0 && m == 1)
            cout << "0 0\n";
        else{
            sum = s - 1;
            digits[0] = 1;
            for(int i = 1; i < m; i++)
                digits[i] = 0;
            int curr = m - 1;
            while(sum > 0){
                if(sum >= 9){
                    digits[curr] = 9;
                    sum -= 9;
                }
                else{
                    digits[curr] += sum;
                    break;;
                }
                curr--;
            }
            for(int i = 0; i < m; i++)
                cout << digits[i];
            cout << " ";
            for(int i = 0; i < m; i++)
                digits[i] = 0;
            sum = s;
            curr = 0;
            while(sum > 0){
                if(sum >= 9){
                    digits[curr] = 9;
                    sum -= 9;
                }
                else{
                    digits[curr] += sum;
                    sum = 0;
                }
                curr++;
            }
            for(int i = 0; i < m; i++)
                cout << digits[i];
            cout << "\n";
        }
    }
    else
        cout << "-1 -1\n";
    return 0;
}
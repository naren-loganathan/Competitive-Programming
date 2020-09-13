#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, count = 1;
    long long int num = 19;
    cin >> k;
    if(k != 1){
        while(count < k){
            num += 9;
            int sum_of_digits = 0;
            for(long long int x = num; x > 0; x /= 10)
                sum_of_digits += x % 10;
            if(sum_of_digits == 10)
                count++;
        }
    }
    cout << num << endl;
    return 0;
}
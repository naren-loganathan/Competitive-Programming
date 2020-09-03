#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, almost_lucky = 0;
    int lucky_nums[] = {4, 7, 47, 44, 74, 77, 444, 474, 447, 744, 774, 777, 477, 747};
    cin >> n;
    for(int i = 0; i < 14; i++){
        if(n % lucky_nums[i] == 0){
            almost_lucky = 1;
            break;
        }
    }
    if(almost_lucky)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
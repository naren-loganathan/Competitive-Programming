#include <iostream>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l = 1, r = 1, count = 0;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 2; i <= n; i++){
        if(arr[i - 1] > arr[i]){
            count++;
            if(count >= 2)
                break;
            l = i - 1;
            while(arr[i - 1] >= arr[i] && i <= n){
                i++;
            }
            r = i - 1;
            if((arr[r] > arr[l - 1] || l == 1) && (arr[l] < arr[r + 1] || r == n))
                continue;
            else{
                count++;
                break;
            }
        }
    }
    if(count == 0 || count == 1)
        cout << "yes\n" << l << " " << r << endl;
    else
        cout << "no" << endl;
    return 0;
}
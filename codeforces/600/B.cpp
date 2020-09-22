#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007

void b_search(int b, vector <int> &arr, int n){
    int low = 0;
    int high = n - 1;
    int mid;
    if(arr[low] > b){
        mid = -1;
    }
    else if(arr[high] <= b){
        mid = n - 1;
    }
    else{
        while(low <= high){
            mid = (low + high) / 2;
            if(arr[mid] > b){
                high = mid - 1;
            }
            else if(arr[mid] <= b && arr[mid + 1] <= b){
                low = mid + 1;
            }   
            else{
                break;
            }    
        }  
    }
    cout << mid + 1 << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        b_search(b[i], a, n);
    }
    cout << endl;
    return 0;
}
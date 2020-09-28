#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n, w, arr[12];
    cin >> k;
    for (int i = 0; i < 12; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 12);
    int sum = 0, count = 0, i = 11;
    while (sum < k) {
        sum += arr[i];
        count += 1;
        if (i == 0) {
            break;
        }
        else {
            i--;
        }
    }
    if (sum < k) {
        count = -1;
    }
    cout << count << endl;
    return 0;
}
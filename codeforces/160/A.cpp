    #include<iostream>
    #include<algorithm>
     
    using namespace std;
     
    int main(){
        int n;
        cin>>n;
        int arr[n], sum =0, greedy[n];
        for(int i=0; i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            greedy[i]=0;
        }
        sort(arr, arr+n);
        for(int i=n-1;i>0;i--){
           greedy[i]+=arr[i];
           greedy[i-1]+=greedy[i];
        }
        greedy[0]+=arr[0];
        for(int i=n-1; i>=0;i--){
            int b=n-i;
            if(greedy[i]>(sum-greedy[i])){
                cout<<b<<endl;
                break;
            }
        }
        return 0;
    }
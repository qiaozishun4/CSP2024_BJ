#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int arrr[100005];
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    int flag=-1;
    int ooo=0;
    for(int i=1;i<=n;i++){
        if(arr[i]!=flag){
            ooo++;
            flag=arr[i];
        }
        arrr[ooo]++;
    }
    int sum=0;
    int k=0;
    for(int i=2;i<=ooo;i++){
        k=0;
        for(int j=1;j<i;j++){
            if(arrr[j]>=arrr[i]-k){
                sum+=arrr[i];
                arrr[j]-=arrr[i];
                break;
            }else{
                sum+=arrr[j];
                k+=arrr[j];
                arrr[j]=0;
            }
        }
    }
    cout<<n-sum;
    return 0;
}
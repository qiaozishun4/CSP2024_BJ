#include <bits/stdc++.h>
using namespace std;
int arr[300005];
bool chose[300005];
int n;
int baoli(int x){
    if(x>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>0;j--){
                if(chose[i]==chose[j]&&arr[i]==arr[j]){
                    sum+=arr[i];
                    break;
                }
            }
        }
        return sum;
    }
    int u=baoli(x+1);
    chose[x]=true;
    return max(baoli(x+1),u);
}
int main(){
freopen("color.in","r",stdin);
freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n<17)
        cout<<baoli(1)<<endl;
    else{
        int sum=0;
        sort(arr+1,arr+n+1);
        int flag=arr[1];
        for(int i=2;i<=n;i++){
            if(arr[i]==flag){
                sum+=flag;
                flag=-1;
            }else{
                flag=arr[i];
            }
        }
        cout<<sum<<endl;
    }
    }
return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
int m[25]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int d1[10]={6,2,5,5,4,5,6,3,7,6};
void f(long long ans1,int sum,int ws){
    if(ws<0)return;
    if(sum>n)return;
    if(ws==0 && sum!=n)return;
    if(ws==0 && sum==n){
        ans=min(ans,ans1);
    }
    for(int i=0;i<=9;i++){
        if(sum+ws*8<n)continue;
        f(ans1*10+i,sum+d1[i],ws-1);
    }
}
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1e9+10;
        cin>>n;
        if(n<=20){
            cout<<m[n]<<endl;
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }else if(n%7==1){
            cout<<"10";
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }else{
            for(int i=1;i<=9;i++)f(i,d1[i],(n%7==0?n/7-1:n/7));
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
/*

*/

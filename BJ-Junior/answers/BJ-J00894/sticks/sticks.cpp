#include<bits/stdc++.h>
using namespace std;
int t,n,a[]={6,2,5,5,4,5,6,3,7,6};
int stick(int x){
    int ans=0;
    while(x){
        ans+=a[x%10];
        x/=10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int f=0;
        cin>>n;
        if(n<=1){
            cout<<"-1\n";
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<'\n';
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<'\n';
        }
        else for(int i=1;i<=1000000;i++)if(stick(i)==n){cout<<i<<'\n',f=1;break;}
        if(!f)cout<<"-1\n";
    }
    return 0;
}

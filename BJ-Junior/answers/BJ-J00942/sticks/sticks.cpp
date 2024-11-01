#include<bits/stdc++.h>
using namespace std;
int t,n,i,a[]={6,2,5,5,4,5,6,3,7,6};
long long ans;
void res(int n,long long num,bool f){
    if(n==0){
        ans=min(ans,num);
        return;
    }
    if(n<0)return;
    for(i=0;i<=9;i++){
        if(!i&&f)continue;
        res(n-a[i],num*10+i,0);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        ans=1e18;
        cin>>n;
        res(n,0,1);
        if(ans==1e18)cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}

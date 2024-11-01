#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
ll n,t,ans=9e18;//6255456376
int c[10]={6,2,5,5,4,5,6,3,7,6};
int f(int k){
    int a=0;
    while(k){
        a+=c[k%10];
        k/=10;
    }
    return a;
}
void dfs(int cn,ll t){
    if(cn>n||t>ans)return ;
    if(cn==n){
        if(t<=0)return ;
        ans=min(ans,t);
        return ;
    }
    for(int i=1;i<=9;i++)dfs(cn+c[i],t*10+i);
    if(t)dfs(cn+6,(t<<3)+(t<<1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=9e18;
        if(n%7==1&&n>=8){
            n-=8;
            cout<<10;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        dfs(0,0);
        if(ans==9e18)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}

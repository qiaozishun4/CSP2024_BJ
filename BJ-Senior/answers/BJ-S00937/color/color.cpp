#include <bits/stdc++.h>
using namespace std;
int n,t,a[1000002],b,r,ma;
void dfs(int dp,int cnt){
    if(dp>n){
            ma=max(ma,cnt);
        return;
    }
    int l=r;
    r=a[dp];
    if(l==a[dp]){
        cnt+=l;
    }
    dfs(dp+1,cnt);
    cnt-=l;
    r=l;
    l=b;
    b=a[dp];
    if(l==a[dp]){
        cnt+=l;
    }
    dfs(dp+1,cnt);
    b=l;
    cnt-=l;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ma=b=r=0;
        dfs(1,0);
        cout<<ma;
    }
    return 0;
}
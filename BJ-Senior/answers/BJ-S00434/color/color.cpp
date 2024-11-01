#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int ans;
int calc(int i){
    bool col[100005];
    for(int j=1;j<=n;j++)col[j]=(i>>n-j)&1;
    int res=0;
    for(int j=1;j<=n;j++){
            int whIF=0;
        for(int k=j-1;k>=1;k--)
            if(col[j]==col[k]&&a[j]==a[k])whIF=a[j];
        res+=whIF;
    }
    return res;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        ans=0;
        for(int i=0;i<(1<<n);i++)
            ans=max(ans,calc(i));
        cout<<ans<<'\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
int t,n,m,vv,l,in[100005],v[100005],xx,s[1000005],chk,minn,ans[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(s,0,sizeof(s));
        cin>>n>>m>>l>>vv;
        for(int i=1;i<=n;i++)cin>>in[i]>>v[i]>>xx;
        for(int i=1;i<=m;i++)cin>>chk,s[chk]=1;
        for(int i=l;i>=0;i--)s[i]+=s[i+1];
        int cnt=0;
        for(int i=1;i<=n;i++)if(v[i]>vv&&s[in[i]]!=0)cnt++;
        if(cnt)cout<<cnt<<" "<<m-1<<'\n';
        else cout<<cnt<<" "<<m<<'\n';
    }
    return 0;
}

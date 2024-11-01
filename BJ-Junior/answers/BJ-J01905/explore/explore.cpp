#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char ch[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        scanf("%lld%lld%lld",&x,&y,&d);
        for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
        map<pair<ll,ll>,ll>mp;
        while(k--){
            if(ch[x+dx[d]][y+dy[d]]=='.'&&x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m)mp[{x,y}]=1,x+=dx[d],y+=dy[d],mp[{x,y}]=1;
            else d=(d+1)%4;
        }
        cout<<mp.size()<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,T,x,y,d,cnt[10]={},dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    char l[1005][1005]={};
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++)cin>>l[j][p];
        }
        cnt[i]=1;
        l[x][y]='0';
        for(int j=1;j<=k;j++){
            int walk=0,px=x+dx[d],py=y+dy[d];
            if(1<=px&&px<=n&&1<=py&&py<=m&&l[px][py]!='x')walk=1;
            if(walk==1){x=px;y=py;
            if(l[x][y]!='0'){cnt[i]++;l[x][y]='0';}}
            else if(walk==0){d=(d+1)%4;}
        }
    }
    for(int i=1;i<=T;i++)cout<<cnt[i]<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,d2,sum=0;
        cin>>n>>m>>k;
        char mp[n+1][m+1];
        bool vis[n+1][m+1];
        cin>>x>>y>>d;
        if(d==2)d2=1;
        else if(d==1)d2=2;
        else d2=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        while(k--){
            if(!vis[x][y])sum++;
            vis[x][y]=1;
            int x1=x+dirx[d],y1=y+diry[d];
            if(mp[x1][y1]=='x'||x1<1||x1>n||y1<1||y1>m){
                d+=1;
                d%=4;
            }
            else{
                x=x1,y=y1;
            }
        }
        cout<<sum+d2;
    }
    return 0;
}

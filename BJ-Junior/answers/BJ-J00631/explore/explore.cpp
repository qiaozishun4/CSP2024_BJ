#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int t,n,m,k,x,y,d;
    cin>>t;
    for(int i=1;i<=t;i++){
        int cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        char c[n+2][m+2];
        int ans[n+2][m+2];
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));

        ans[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int r=1;r<=m;r++){
                cin>>c[j][r];
            }
        }
        while(k>0){
            while((x+dx[d])<1||(x+dx[d])>n||(y+dy[d])<1||(y+dy[d])>m||c[x+dx[d]][y+dy[d]]=='x'){
                d=(d+1)%4;
                k--;

            }
            if(k>0){
                x=x+dx[d];
                y=y+dy[d];
                ans[x][y]=1;
                k--;
            }

            }
        for(int j=1;j<=n;j++){
            for(int r=1;r<=m;r++){
                cnt+=ans[j][r];
            }
        }

     cout<<cnt<<endl;
    }
    return 0;
}

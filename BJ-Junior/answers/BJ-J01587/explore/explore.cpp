#include<bits/stdc++.h>
using namespace std;
int a[2005][2005],n,m,k,ans;bool flag[2005][2005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    for(int o=1;o<=T;o++){
            int x,y,t;ans=0;
        cin>>n>>m>>k>>x>>y>>t;
        for(int i=1;i<=1001;i++){
            for(int j=1;j<=1001;j++){
                a[i][j]=0;flag[i][j]=0;
            }
        }
        for(int i=1;i<=1001;i++){
            a[0][i]=1;a[n+1][i]=1;
        }
        for(int i=1;i<=1001;i++){
            a[i][0]=1;a[i][m+1]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char x;cin>>x;
                if(x=='x')a[i][j]=1;
            }
        }
        for(int i=0;i<=k;i++){
            if(flag[x][y]==0){
                ans++;flag[x][y]=1;
            }
            if(i==k)break;
            if(a[x+dx[t]][y+dy[t]]==1){
                t=(t+1)%4;
            }else {
                x=x+dx[t];y=y+dy[t];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
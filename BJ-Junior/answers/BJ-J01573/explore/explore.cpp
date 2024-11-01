#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long t,n,m,k,x,y,d,ans=1,flag[N][N];
char mp[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(long long l=1;l<=t;l++){
        ans=1;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                flag[i][j]=0;
            }
        }
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(long long i=1;i<=k;i++){
            if(d==0){
                if(x>=1&&x<=n&&(y+1)>=1&&(y+1)<=m&&mp[x][y+1]!='x'){
                    if(flag[x][y+1]==0){
                        ans++;
                        flag[x][y+1]=1;
                    }
                    x=x;
                    y=y+1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if((x+1)>=1&&(x+1)<=n&&y>=1&&y<=m&&mp[x+1][y]!='x'){
                    if(flag[x+1][y]==0){
                        ans++;
                        flag[x+1][y]=1;
                    }
                    x=x+1;
                    y=y;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(x>=1&&x<=n&&(y-1)>=1&&(y-1)<=m&&mp[x][y-1]!='x'){
                    if(flag[x][y-1]==0){
                        ans++;
                        flag[x][y-1]=1;
                    }
                    x=x;
                    y=y-1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                if((x-1)>=1&&(x-1)<=n&&y>=1&&y<=m&&mp[x-1][y]!='x'){
                    if(flag[x-1][y]==0){
                        ans++;
                        flag[x-1][y]=1;
                    }
                    x=x-1;
                    y=y;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
char mp[1005][1005];
int flag[1005][1005];
int hang[10]={0,1,0,-1};
int lie[10]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                flag[i][j]=0;
            }
        }
        int x_now=x,y_now=y;
        flag[x_now][y_now]=1;
        int i=1;
        for(int i=1;i<=k;i++){
            if(x_now+hang[d]<1||x_now+hang[d]>n||y_now+lie[d]<1||y_now+lie[d]>m||mp[x_now+hang[d]][y_now+lie[d]]=='x'){
                d=(d+1)%4;
            }
            else{
                x_now+=hang[d%4];
                y_now+=lie[d%4];
                flag[x_now][y_now]=1;
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(flag[i][j]==1){
                        sum++;
                }
            }
        }
        if(T==0) cout<<sum;
        else cout<<sum<<endl;
    }
    return 0;
}

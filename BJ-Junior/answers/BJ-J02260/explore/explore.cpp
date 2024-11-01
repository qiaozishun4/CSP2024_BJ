#include<bits/stdc++.h>
using namespace std;
int t;
char a[1001][1001];
bool flag[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
   cin>>t;
   for(int i=1;i<=t;i++){
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int k=1;k<=n;k++){
        for(int j=1;j<=m;j++){
            flag[k][j]=false;
        }
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=m;j++){
            cin>>a[k][j];
        }
    }
    int ans=1;
    while(k--){
        int nx=x,ny=y;
        if(d==0){
            ny++;
        }else if(d==1){
            nx++;
        }else if(d==2){
            ny--;
        }else{
            nx--;
        }
        if(nx<=n&&nx>0&&ny<=m&&ny>0&&a[nx][ny]=='.'){
            x=nx;
            y=ny;
            if(!flag[nx][ny])ans++;
            flag[nx][ny]=true;
        }else{

            d=(d+1)%4;
        }
    }
    cout<<ans<<'\n';

   }
   fclose(stdin);
   fclose(stdout);
    return 0;
}



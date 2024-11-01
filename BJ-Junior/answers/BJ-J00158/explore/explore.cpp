#include<iostream>
 using namespace std;
 int x1[4]={0,1,0,-1};
 int y1[4]={1,0,-1,0};
 int x,y,d;
 int n,m,k;
 char c[1005][1005];
 int a[1005][1005];
 int ans;
 void mov(){
     if(c[x+x1[d]][y+y1[d]]=='x'||x+x1[d]>n||y+y1[d]>m||x+x1[d]<=0||y+y1[d]<=0) d=(d+1)%4;
     else{
        x+=x1[d];
        y+=y1[d];
        if(a[x][y]==0) a[x][y]=1,ans++;
     }
     //cout<<x<<' '<<y<<' '<<d<<endl;
 }
 void solve(){
     cin>>n>>m>>k;
     cin>>x>>y>>d;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            a[i][j]=0;
        }
     }
     ans=1;
     a[x][y]=1;
     while(k--) mov();
     cout<<ans<<endl;
 }
 int main(){
     freopen("explore.in","r",stdin);
     freopen("explore.out","w",stdout);
     int T;
     cin>>T;
     while(T--) solve();
     return 0;
 }

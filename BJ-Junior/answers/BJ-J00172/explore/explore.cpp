#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d,ans;
char a[1005][1005];
long long v[1005][1005];
long long xx[10],xy[10];
int main(){
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  cin>>T;
  xx[0]=0;xx[1]=1;xx[2]=0;xx[3]=-1;
  xy[0]=1;xy[1]=0;xy[2]=-1;xy[3]=0;
  while(T--){
     cin>>n>>m>>k>>x>>y>>d;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             cin>>a[i][j];
         }
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             v[i][j]=0;
         }
     }
     v[x][y]=1;ans=1;
     for(int i=1;i<=k;i++){
         if(x+xx[d]<=0||y+xy[d]<=0||x+xx[d]>n||y+xy[d]>m||a[x+xx[d]][y+xy[d]]=='x') d=(d+1)%4;
         else{
             x=x+xx[d];
             y=y+xy[d];
             if(v[x][y]==0){
                v[x][y]=1;
                ans++;
             }
         } 
     }
     cout<<ans<<endl;
  }
  return 0;
}

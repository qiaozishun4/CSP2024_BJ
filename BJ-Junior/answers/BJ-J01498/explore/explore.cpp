#include<bits/stdc++.h>
using namespace std;
int a[2]={1,-1},s,b,[4][2]={0,1}{1,0},{0,-1},{-1,0};
int main(){
freopen("ditutanxian.in","r",stdin);
freopen("ditutanxian.out","w",stdout);
     bool ma[maxn][maxn];
     int T;
     cin>>T;
     for(int i=1;i<=T;i++){
     int n,m,c,x,y,d;
     cin>>n>>m>>c>>x>>y>>d;
     char mc[m+1][m+1];
     for(int k=1;k<=m;k++){
     for(int j=1;j<=m;j++)
     cin>>mc[k][j];
     }
     if(c==1){
     if(m1[x+b[d][0]][y+b[d][1]])=='.'{
     cout<<2;
     }else
     cout<<1;
     return 0;
     }
     bool m2[m+1];
     char m1[m+1]];
     for(int k=1;k<=n;k++){
     m1[k]=mc[1][k];
        if(m1[k]=='.'){
        m2[k]=1;
        }else{
        m2[k]=0;
        }
     }
     if(d==1||d==3){
     c--;
     d=(d+1)%4;
     d/=2;
     }
     for(int j=1;j<=c;j++){
     if(ma[y]==0){
     ma[y]=1;
     s++;
     }
     if(m2[y+a[d]]==0){
     c--;
     d=(d-1)%2;
     continue;
     }
     y+=a[d];
     }
     cout<<s+1<<endl;
     }
return 0;
}

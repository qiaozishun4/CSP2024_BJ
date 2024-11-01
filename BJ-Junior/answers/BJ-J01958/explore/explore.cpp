#include <bits/stdc++.h>
using namespace std;
int jr[1005][1005];
bool vis[1005][1005];
int main(){
int t,n,m,k,x,y,d;
char a;
cin>>t;
while(t--){
cin>>n>>m>>k>>x>>y>>d;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
cin>>a;
if(a=='.'){
jr[i][j]=1;
}
else jr[i][j]=0;
}
}
while(k>0){
vis[x][y]=1;
if(d==0){
if(jr[x][y+1]==1&&y+1<=m) y=y+1;
else d=1;
k--;
}
else if(d==1){
if(jr[x+1][y]==1&&x+1<=n) x=x+1;
else d=2;
k--;
}
else if(d==2){
if(jr[x][y-1]==1&&y-1>=1) y=y-1;
else d=3;
k--;
}
else if(d==3){
if(jr[x-1][y]==1&&x-1>=1) x=x-1;
else d=0;
k--;
}
}
vis[x][y]=1;
int cnt=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
if(vis[i][j]==1) cnt++;
}
}
cout<<cnt<<endl;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
jr[i][j]=0;
vis[i][j]=0;
}
}
}
return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int T,n,m,k,x,y,sum=1,K;
char a[1005][1005];
cin>>T;
while(T--){
cin>>n>>m>>K;
cin>>x>>y>>k;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
cin>>a[i][j];
while(K--){
if(k==0&&x+1<=n&&a[x+1][y]=='.'){
x++;
sum++;
}
else if(k==1&&y+1<=m&&a[x][y+1]=='.'){
y++;
sum++;
}
else if(k==2&&x-1>=1&&a[x-1][y]=='.'){
x--;
sum++;
}
else if(k==3&&y-1>=1&&a[x][y-1]=='.'){
y--;
sum++;
}
else k=(k+1)%4;
}
cout<<sum<<endl;
}
return 0;
}

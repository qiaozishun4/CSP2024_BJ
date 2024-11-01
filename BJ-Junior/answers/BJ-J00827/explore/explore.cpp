#include<iostream>
using namespace std;
int t,n,m,d,x,y,x2[4]={0,1,0,-1},y2[4]={1,0,-1,0};
char a[1010][1010];
bool b[1010][1010];
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
cin>>t;
while(t--){
int sum=0;
cin>>n>>m>>k>>x>>y>>d;
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {cin>>a[i][j];b[i][j]=0;}
b[x][y]=1;
for(int i=1;i<=k;i++)
{
int temp1=x+x2[d],temp2=y+y2[d];
if(temp1>0&&temp1<=n&&temp2>0&&temp2<=m&&a[temp1][temp2]=='.')
{
x=temp1;
y=temp2;
}
else d=(d+1)%4;
b[x][y]=1;
}
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(b[i][j]) sum++;
cout<<sum<<endl;
}
return 0;
}

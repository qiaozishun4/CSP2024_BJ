#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =10005;
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int n,m,k,d,x,y,xx,yy,t;
cin>>t;
char q;
for(int p=1;p<=t;p++){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    bool s[n+5][m+5];
    bool s1[n+5][m+5];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s1[i][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>q;
            if(q=='x')
                s[i][j]=0;
            else if(q=='.')
                s[i][j]=1;
        }}
    int cnt=1;
    s1[x][y]=1;
    for(int i=1;i<=k;i++){
        xx=x;yy=y;
        if(d==0)
            yy++;
        else if(d==1)
            xx++;
        else if(d==2)
            yy--;
        else
            xx--;
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[xx][yy]){
            x=xx;y=yy;
            if(s1[x][y]==0){
                cnt++;
                s1[x][y]=1;
            }
        }
        else{
            d=(d+1)%4;
        }
}
cout<<cnt<<endl;
}
return 0;
}

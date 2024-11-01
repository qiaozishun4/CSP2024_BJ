#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,a[1145][1145],myexploreans,nxtx,nxty;
string s;
int main(){
    freopen("explore.in","r",stdin),freopen("explore.out","w",stdout),scanf("%d",&t);
    while(t--){
        myexploreans=0,scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d),memset(a,0,sizeof a);
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++)a[i][j]=(s[j-1]=='x');
        }
        while(k--)((!a[x][y])?(myexploreans++,a[x][y]=2):0),nxtx=x+(d==1)-(d==3),nxty=y+(d==0)-(d==2),((1<=nxtx&&nxtx<=n&&1<=nxty&&nxty<=m&&a[nxtx][nxty]!=1)?(x=nxtx,y=nxty):(d=(d+1)%4));
        ((!a[x][y])?(myexploreans++,a[x][y]=2):0),cout<<myexploreans<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,ans=0;
char a[1002][1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
            for(int s=1;s<=m;s++)
                cin>>a[j][s];

        for(int j=0;j<=n+1;j++){
            a[j][0]='x';a[j][m+1]='x';
        }
        for(int j=0;j<=m+1;j++){
            a[0][j]='x';a[n+1][j]='x';
        }
        a[x][y]='1';
        for(int j=1;j<=k;j++){
            ans=0;
            switch(d){
                case 0:{
                    if(a[x][y+1]!='x')a[x][++y]='1';
                    else d=1;
                    break;
                }
                case 1:{
                    if(a[x+1][y]!='x')a[++x][y]='1';
                    else d=2;
                    break;
                }
                case 2:{
                    if(a[x][y-1]!='x')a[x][--y]='1';
                    else d=3;
                    break;
                }
                case 3:{
                    if(a[x-1][y]!='x')a[--x][y]='1';
                    else d=0;
                    break;
                }
            }
        }
        for(int s=1;s<=n;s++)
            for(int j=1;j<=m;j++)
                if(a[s][j]=='1')ans++;
        cout<<ans<<endl;
    }
    return 0;
}
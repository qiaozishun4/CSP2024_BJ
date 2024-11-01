#include <bits/stdc++.h>
using namespace std;
char a[1050][1050]={'0','0'};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,ans=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>a[i][j];
        for(int i=1;i<=k;i++)
        {
            if(d==0 && a[x][y+1]=='.'){
                ans++;y++;a[x][y]='#';
            }
            else if(d==1 && a[x+1][y]=='.'){
                ans++;x++;a[x][y]='#';
            }
            else if(d==2 && a[x][y-1]=='.'){
                ans++;y--;a[x][y]='#';
            }
            else if(d==3 && a[x-1][y]=='.'){
                ans++;x--;a[x][y]='#';
            }

            else if(d==0 && a[x][y+1]=='#'){
                y++;a[x][y]='#';
            }
            else if(d==1 && a[x+1][y]=='#'){
                x++;a[x][y]='#';
            }
            else if(d==2 && a[x][y-1]=='#'){
                y--;a[x][y]='#';
            }
            else if(d==3 && a[x-1][y]=='#'){
                x--;a[x][y]='#';
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}

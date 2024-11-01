#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int ex=0;ex<t;ex++){
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            cin>>a[i][j];
        }
        for(int i=0;i<k;i++){
            if(!((d==0&&1<=x<=n&&1<=y+1<=m&&(a[x][y+1]=='.'||a[x][y+1]=='a'))||(d==1&&1<=x+1<=n&&1<=y<=m&&(a[x+1][y]=='.'||a[x+1][y]=='a'))||(d==2&&1<=x<=n&&1<=y-1<=m&&(a[x][y-1]=='.'||a[x][y-1]=='a'))||(d==3&&1<=x-1<=n&&1<=y<=m&&(a[x-1][y]=='.'||a[x-1][y]=='a')))){
                d=(d+1)%4;
                cout<<"turn"<<" "<<d<<endl;
            }
            else {
                a[x][y]='a';
                if(d==0)
                y++;
                if(d==1)
                x++;
                if(d==2)
                y--;
                if(d==3)
                x--;
                cout<<x<<" "<<y<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='a')
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool f[1001][1001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k;
    int s;
    cin>>s;
    for(int i=1;i<=s;i++){
        int x,y,d,xx,xy;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--,y--;
        f[x][y]=true;
        int ans=1;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=k;j++){
            if(d==0) xx=0,xy=1;
            if(d==1) xx=1,xy=0;
            if(d==2) xx=0,xy=-1;
            if(d==3) xx=-1,xy=0;
            if(x+xx>=0&&y+xy>=0&&x+xx<n&&y+xy<m&&a[x+xx][y+xy]=='.'&&a[x+xx][y+xy]!='x'){
                x+=xx,y+=xy;
                if(f[x][y]==false){
                    ans++;
                    f[x][y]=true;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int j=0;j<=n;j++){
            for(int l=0;l<=m;l++){
                f[j][l]=false;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

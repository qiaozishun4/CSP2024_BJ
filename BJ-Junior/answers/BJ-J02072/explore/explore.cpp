#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,x,y,d,f[1005][1005];
int posx[4]={0,1,0,-1};
int posy[4]={1,0,-1,0};
char a[1005][1005];

int main()
{
    freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&a[i][j]);
                f[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++) a[i][m+1]='x';
        for(int i=1;i<=m;i++) a[n+1][i]='x';
        while(k--){
            int fx=x+posx[d];
            int fy=y+posy[d];
            if(a[fx][fy]=='.' and fx>=1 and fx<=n and fy>=1 and fy<=m){
                if(f[fx][fy]==0) ans++;
                f[fx][fy]=1;
                x=fx,y=fy;
            }else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}

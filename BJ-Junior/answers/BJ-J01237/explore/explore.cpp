#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,ans=1,i,j;
bool b[1010][1010],f[1010][1010];
char q;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        ans=1;
        memset(f,0,sizeof(f));
        cin>>n>>m>>k>>x>>y>>d;
        i=x,j=y;
        f[i][j]=1;
        for(int c=1;c<=n;c++)
            for(int e=1;e<=m;e++){
                cin>>q;
                if(q=='.')b[c][e]=0;
                else b[c][e]=1;
            }
        while(k--){
            if(i==n&&d==1||j==m&&d==0||i==1&&d==3||j==1&&d==2){
                d=(d+1)%4;
                continue;
            }
            else if(b[i][j+1]==1&&d==0||b[i+1][j]==1&&d==1||b[i][j-1]==1&&d==2||b[i-1][j]==1&&d==3){
                d=(d+1)%4;
                continue;
            }
            if(d==0)j++;
            else if(d==1)i++;
            else if(d==2)j--;
            else if(d==3)i--;
            if(f[i][j]==0)ans++,f[i][j]=1;
        }
        if(t==0)cout<<ans;
        else cout<<ans<<endl;
    }
    return 0;
}

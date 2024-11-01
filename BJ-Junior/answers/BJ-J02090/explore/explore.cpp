#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d,ans;
int a[2000][2000];
char s;
bool z(int x,int y){
    if(a[x][y]==0)return 0;
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        ans=1;
        for(int i=1;i<=n;i++)a[i][0]=0;
        for(int i=1;i<=m;i++)a[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s;
                if(s=='.')a[i][j]=1;
                else a[i][j]=0;
            }
        }
        a[x][y]=2;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(z(x,y+1)){
                    y=y+1;
                    if(a[x][y]==1){ans++;a[x][y]=2;}
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(z(x+1,y)){x=x+1;if(a[x][y]==1){ans++;a[x][y]=2;}}
                else d=(d+1)%4;
            }
            else if(d==2){
                if(z(x,y-1)){y=y-1;if(a[x][y]==1){ans++;a[x][y]=2;}}
                else d=(d+1)%4;
            }
            else if(d==3){
                if(z(x-1,y)){x=x-1;if(a[x][y]==1){ans++;a[x][y]=2;}}
                else d=(d+1)%4;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}



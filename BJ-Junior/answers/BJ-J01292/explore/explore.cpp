#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
char a[1001][1001];
int f[4][2]={0,1,1,0,0,-1,-1,0};
bool b[1001][1001];
int ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
//        cout<<endl;
        while(k--){
            if(a[x+f[d][0]][y+f[d][1]]=='.'){
                x+=f[d][0];
                y+=f[d][1];
                if(b[x][y]==0) ans++;
                b[x][y]=1;
//                cout<<"go to "<<x<<" "<<y<<endl;
            }
            else{
                d++;
                if(d==4) d=0;
//                cout<<"change to"<<d<<endl;
            }
        }
        cout<<ans<<endl;
        memset(b,0,sizeof b);
    }
    return 0;
}

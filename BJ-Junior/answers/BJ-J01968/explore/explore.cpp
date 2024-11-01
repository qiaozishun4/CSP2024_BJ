#include<bits/stdc++.h>
using namespace std;
int t;
bool a[1005][1005]={},b[1005][1005]={};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            char tmp;
            cin>>tmp;
            if(tmp=='.')a[i][j]=1;
        }
        while(k--){
            int _x=x,_y=y;
            if(!d)y++;
            if(d==1)x++;
            if(d==2)y--;
            if(d==3)x--;
            if(!x||!y||x>n||y>m||!a[x][y]){
                d=(d+1)%4;
                x=_x,y=_y;
            }
            else{
                b[x][y]=1;
                cout<<"x="<<x<<" y="<<y<<endl;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(b[i][j])ans++;
        cout<<ans+1;
    }
    return 0;
}

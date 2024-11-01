#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char a[N][N];
int T,n,m,k,x,y,d;
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int flag=0;
        for(int i=1;i<=k;i++){
            if(d==0&&a[x][y]=='.'){
                y+1;
                flag++;
            }else if(d==1&&a[x][y]=='.'){
                x+1;
                flag++;
            }else if(d==2&&a[x][y]=='.'){
                y-1;
                flag++;
            }else if(d==3&&a[x][y]=='.'){
                x-1;
                flag++;
            }else{
                d++;
                if(d==4&&a[x][y]=='.'){
                    d=0;
                }
            }
        }
        cout<<flag<<endl;
    }
    return 0;
}

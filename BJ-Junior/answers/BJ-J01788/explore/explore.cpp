#include <bits/stdc++.h>
using namespace std;
int T;
bool b[1010][1010];
char a[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(b,0,sizeof(b));
        int cnt=1;
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            int x1=x;
            int y1=y;
            if(d==0) y1++;  
            else if(d==1) x1++;
            else if(d==2) y1--;
            else if(d==3) x1--;
            if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x'){
                d=(d+1)%4;
                continue;
            }
            x=x1;
            y=y1;
            if(b[x][y]==1) continue;
            b[x][y]=1;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
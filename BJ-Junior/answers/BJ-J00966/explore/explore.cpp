#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,x,y,d,p[4]={0,1,0,-1},q[4]={1,0,-1,0},g;
bool a[1111][1111];
char c[1111][1111];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        g=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
        a[x][y]=g=1;
        for(int i=1;i<=k;i++){
            if(x+p[d]>n||x+p[d]<=0||y+q[d]>m||y+q[d]<=0||c[x+p[d]][y+q[d]]=='x') d=(d+1)%4;
            else{
                x+=p[d];
                y+=q[d];
                if(!a[x][y]){
                    g++;
                    a[x][y]=1;
                }
            }
        }
        cout<<g<<endl;
    }
    return 0;
}

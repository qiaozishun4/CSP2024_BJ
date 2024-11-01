#include<iostream>
#include<cstring>
using namespace std;
int T,n,m,k,x,y,d,a[4]={0,1,0,-1},b[4]={1,0,-1,0},c[1005][1005],f[1005][1005],num;
char o;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>o;
                if(o=='.') c[i][j]=1;
                else c[i][j]=0;
            }
        }
        memset(f,0,sizeof(f));
        num=0;
        for(int i=1;i<=k;i++){
            if(f[x][y]==0&&c[x][y]==1){
                f[x][y]=1;
                num++;
            }
            if(c[x+a[d]][y+b[d]]==1){
                x+=a[d];
                y+=b[d];
            }
            else d=(d+1)%4;
        }
        if(f[x][y]==0&&c[x][y]==1){
            f[x][y]=1;
            num++;
        }
        cout<<num<<endl;
    }
    return 0;
}

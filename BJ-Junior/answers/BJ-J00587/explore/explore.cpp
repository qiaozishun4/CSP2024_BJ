#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int fx[5]={0,1,0,-1,0};
int fy[5]={1,0,-1,0,0};
char a[1010][1010];
bool b[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int cnt=1,x,y,d;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        //cout<<n<<" "<<m<<" "<<k<<endl;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }*/
        b[x][y]=true;
        for(int i=1;i<=k;i++){
            int tx=x+fx[d],ty=y+fy[d];
            if(a[tx][ty]=='.'){
                x=tx;
                y=ty;
                //cout<<x<<"  "<<y<<endl;
                if(!b[x][y]){
                    b[x][y]=true;
                    cnt++;
                }
            }else{
                d=(d+1)%4;
                //cout<<d<<endl;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

char a[1010][1010];
int n,m,k;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    while(T>0){
        int x0,y0,d0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x0,&y0,&d0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        a[x0][y0]='#';
        int x=x0,y=y0,d=d0;
        for(int i=1;i<=k;i++){
            int dx=x,dy=y;
            if(d==0){
                dx=x;
                dy=y+1;
            }
            else if(d==1){
                dx=x+1;
                dy=y;
            }
            else if(d==2){
                dx=x;
                dy=y-1;
            }
            else if(d==3){
                dx=x-1;
                dy=y;
            }
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]!='x'){
                x=dx;
                y=dy;
                a[x][y]='#';
            }
            else{
                d=(d+1)%4;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='#'){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;

        T--;
    }
    return 0;
}

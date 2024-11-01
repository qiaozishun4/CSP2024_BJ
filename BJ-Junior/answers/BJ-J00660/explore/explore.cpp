#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for(int bs=1;bs<=t;bs++){
        int n,m,k,ans=1;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        char a[1005][1005]={0};
        char b[1005][1005]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        b[x][y]=1;
        int nx,ny;
        for(int nk=1;nk<=k;nk++){

            if(d==0){   //xia yi bu wei zhi ji suan
                nx=x;
                ny=y+1;
            }else if(d==1){
                nx=x+1;
                ny=y;
            }else if(d==2){
                nx=x;
                ny=y-1;
            }else if(d==3){
                nx=x-1;
                ny=y;
            }

            int f=0;
            if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                if(a[nx][ny]=='.'){
                    f=1;
                    x=nx;
                    y=ny;
                    if(b[x][y]==0){
                        ans+=1;
                    }
                    b[x][y]=1;
                }
            }
            if(f==0){
                d=(d+1)%4;
            }

        }
        printf("%d\n",ans);

    }

    return 0;
}

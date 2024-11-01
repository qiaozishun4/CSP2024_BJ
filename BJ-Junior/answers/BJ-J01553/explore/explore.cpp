#include <iostream>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        int x0,y0,d0,x,y,sum=0;
        cin >>n>>m>>k>>x0>>y0>>d0;
        int d =d0;




        char r [1009][1009];
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin >> r[j][l];
            }
        }

        r[x0][y0] = 'r';
        for(int i=1;i<=k;i++){
            x = x0+dx[d];
            y = y0+dy[d];
            if(x<=n&&1<=x&&y<=m&&1<=y&&r[x][y]!='x'){
                x0=x;
                y0=y;
                r[x0][y0] = 'r';
            }else{
                x=x0;
                y=y0;
                d = (d+1)%4;
                r[x0][y0] = 'r';
            }

        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){

                if(r[j][l]=='r') sum++;
            }

        }
        cout <<sum<<endl;

    }





    return 0;
}

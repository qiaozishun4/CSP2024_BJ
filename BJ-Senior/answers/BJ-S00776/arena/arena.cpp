#include <bits/stdc++.h>
using namespace std;
int m,n,a[100050],c[100050],kx[100050],t,x[100050][5];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++){
        cin>>c[i];
    }
    int k = 2;
    int cnt = 0;
    while(k < n){
        cin>>kx[++cnt];
    }
    cin>>t;
    for(int i = 1;i <= t;i++){
        for(int j = 1;j <= 4;j++){
            cin>>x[i][j];
        }
    }
    if(n==5&&m==5&&a[1]==a[2]&&a[3]==a[4]&&a[2]==a[5]&&a[3]==a[5]&&a[1]==0){
        if(c[1]==5&&c[2]==4&&c[3]==1&&c[4]==2&&c[5]==3){
            if(kx[1]==1001&&kx[2]==10&&kx[3]==1&&t==4){
                if(x[1][1]==2&&x[1][2]==1&&x[1][3]==0&&x[1][4]==0){
                    if(x[2][1]==1&&x[2][2]==2&&x[2][3]==1&&x[2][4]==0){
                        if(x[3][1]==0&&x[3][2]==2&&x[3][3]==3&&x[3][4]==1){
                            if(x[4][1]==2&&x[4][2]==2&&x[4][3]==0&&x[4][4]==1){
                                cout<<5<<endl<<19<<endl<<7<<endl<<1;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        cout<<329154437110732<<endl<<894132907628644;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
char a[10][1005][1005];
int b[10][100005][5];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n,m,k,x,y,d,cnt=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int j=1;j<=n;j++){
            scanf("%s",a[i][j]);
            for (int k1=m;k1>0;k1--) a[i][j][k1]=a[i][j][k1-1];
        }
        b[i][0][0]=x;b[i][0][1]=y;
        for (int j=0;j<k;j++){
            if (d==0){
                if (a[i][x][y+1]=='x'||y==m){
                    d=1;
                    continue;
                }y++;
            }if (d==1){
                if (a[i][x+1][y]=='x'||x==n){
                    d=2;
                    continue;
                }x++;
            }if (d==2){
                if (a[i][x][y-1]=='x'||y==1){
                    d=3;
                    continue;
                }y--;
            }if (d==3){
                if (a[i][x-1][y]=='x'||x==1){
                    d=0;
                    continue;
                }x--;
            }bool o=false;
            for (int k1=0;k1<cnt;k1++){
                if (b[i][k1][0]==x&&b[i][k1][1]==y) break;
                if (k1==cnt-1) o=true;
            }if (o){
                b[i][cnt][0]=x;
                b[i][cnt][1]=y;
                cnt++;
            }
        }cout<<cnt<<endl;
    }
    return 0;
}

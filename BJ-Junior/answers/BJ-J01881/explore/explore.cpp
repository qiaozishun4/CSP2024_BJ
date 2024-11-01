#include<bits/stdc++.h>
using namespace std;
string s;
int t;
int n,m,k,x,y,d,a[1005][1005],b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int pt=1;pt<=t;pt++){
        for(int i=0;i<=1004;i++){
            for(int j=0;j<=1004;j++){
                a[i][j]=0;
                b[i][j]=0;
            }
        }
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        b[x][y]++;
        for(int i=1;i<=n;i++){
            string placee;
            cin>>placee;
            for(int j=1;j<=m;j++){
                if(placee[j-1]=='.'){
                    a[i][j]=1;
                }
                else{
                    a[i][j]=0;
                }
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                int nxtx=x;
                int nxty=y+1;
                if(a[nxtx][nxty]==0){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    x=nxtx;
                    y=nxty;
                    b[x][y]++;
                    continue;
                }
            }
            if(d==1){
                int nxtx=x+1;
                int nxty=y;
                if(a[nxtx][nxty]==0){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    x=nxtx;
                    y=nxty;
                    b[x][y]++;
                    continue;
                }
            }
            if(d==2){
                int nxtx=x;
                int nxty=y-1;
                if(a[nxtx][nxty]==0){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    x=nxtx;
                    y=nxty;
                    b[x][y]++;
                    continue;
                }
            }
            if(d==3){
                int nxtx=x-1;
                int nxty=y;
                if(a[nxtx][nxty]==0){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    x=nxtx;
                    y=nxty;
                    b[x][y]++;
                    continue;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]!=0){
                    sum++;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}

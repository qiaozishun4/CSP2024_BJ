#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        x-=1;
        y-=1;
        char c[n][m];
        for (int j=0;j<n;j++) for (int l=0;l<m;l++) cin>>c[j][l];
        int a[k][3]={x,y,d},r=1;
        for (int j=1;j<=k;j++){
            int x0,y0;
            if (d==0){
                x0=x;
                y0=y+1;
            }
            else if (d==1){
                x0=x+1;
                y0=y;
            }
            else if (d==2){
                x0=x;
                y0=y-1;
            }
            else{
                x0=x-1;
                y0=y;
            }
            if (x0>=0&&x0<n&&y0>=0&&y0<m&&c[x0][y0]=='.'){
                bool p=true,q=false;
                for (int l=0;l<r;l++) if (a[l][0]==x0&&a[l][1]==y0){
                    if (a[l][2]==d) q=true;
                    p=false;
                    break;
                }
                if (q) break;
                if (p){
                    a[r][0]=x0;
                    a[r][1]=y0;
                    a[r][2]=y0;
                    r++;
                }
                x=x0;
                y=y0;
            }
            else d=(d+1)%4;
        }
        cout<<r<<endl;
    }
    return 0;
}
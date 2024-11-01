#include <bits/stdc++.h>
using namespace std;
int xx(int a,int d){
if(d==0||d==2) return a;
if(d==1) return a+1;
if(d==3) return a-1;}
int yy(int a,int d){
    if(d==1||d==3) return a;
    if(d==0) return a+1;
    if(d==2) return a-1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    char a[1005][1005];
    int x,y,k,T,x0,y0,d0;
    int n,m;
    int d[4]={0,1,2,3};
    cin>>T;
    int sum[7]={1,1,1,1,1,1,1};
    for(int b=0;b<T;b++){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int c=0;c<n;c++){
        for(int j=0;j<m;j++){
            cin>>a[c][j];
        }

        }
        for(int i=1;i<=k;i++){
            if(1<=xx(x0,d0)<=n&&1<=yy(y0,d0)<=m&&a[xx(x0,d0)][yy(y0,d0)]=='.'){
                x0=xx(x0,d0);
                y0=yy(y0,d0);
                sum[b]++;
                continue;
            }
            else{
                d0=(d0+1)%4;
                continue;
            }
        }
    }
    for(int i=0;i<T;i++){
        cout<<sum[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;}

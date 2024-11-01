#include<bits/stdc++.h>
using namespace std;
int t;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int n,m,k;
    int x,y,d;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int aa[1005][1005]={};
        int sum=1;
        aa[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0) y++;
            if(d==1) x++;
            if(d==2) y--;
            if(d==3) x--;
            if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='.'){
                if(aa[x][y]==0){
                    sum++;
                    aa[x][y]=1;
                }
            }else{
                if(d==0) y--;
                if(d==1) x--;
                if(d==2) y++;
                if(d==3) x++;
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

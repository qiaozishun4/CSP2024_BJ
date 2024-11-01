#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n,m,k,x,y,d;
        int sum=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char a[1001][1001];
        for(int o=1;o<=n;o++){
            for(int u=1;u<=m;u++){
                cin>>a[o][u];
            }
        }
        a[x][y]='*';
        for(int j=1;j<=k;j++){
            if(d==0&&y+1<=m&&a[x][y+1]!='X'){
                y=y+1;
                if(a[x][y]!='*'){
                    sum++;
                }
                a[x][y]='*';
                continue;
            }else if(d==0){
                d++;
                continue;
            }
            if(d==1&&x+1<=n&&a[x+1][y]!='X'){
                x=x+1;
                if(a[x][y]!='*'){
                    sum++;
                }
                a[x][y]='*';
                continue;
            }else if(d==1){
                d++;
                continue;
            }
            if(d==2&&y-1>=1&&a[x][y-1]!='X'){
                y=y-1;
                if(a[x][y]!='*'){
                    sum++;
                }
                a[x][y]='*';
                continue;
            }else if(d==2){
                d++;
                continue;
            }
            if(d==3&&x-1>=1&&a[x-1][y]!='X'){
                x=x-1;
                if(a[x][y]!='*'){
                    sum++;
                }
                a[x][y]='*';
                continue;
            }else if(d==3){
                d=0;
                continue;
            }
        }
        cout<<sum<<' ';
    }
    return 0;
}

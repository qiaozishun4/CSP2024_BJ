
#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        memset(b,0,sizeof(b));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>a[j][k];
            }
        }
        long long cnt=1;
        b[x][y]=1;
        for(int j=1;j<=k;j++){
            if(d==0){
                if(x<=n && (y+1)<=m  && x>=1  && (y+1)>=1 && a[x][y+1]!='x'){
                    if(b[x][y+1]!=1){
                        cnt++;
                    }
                    b[x][y+1]=1;
                    y++;

                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){

                if((x+1)<=n && y<=m  && (x+1)>=1  && y>=1  && a[x+1][y]!='x'){
                    if(b[x+1][y]!=1){
                        cnt++;
                    }
                    b[x+1][y]=1;
                    x++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(x<=n && (y-1)<=m && x>=1  && (y-1)>=1 && a[x][y-1]!='x'){
                    if(b[x][y-1]==0){
                        cnt++;
                    }


                    b[x][y-1]=1;
                    y--;
                }else{
                    d=(d+1)%4;
                }
            }else{
                if((x-1)<=n && y<=m  && (x-1)>=1  && y>=1  && a[x-1][y]!='x'){
                    if(b[x-1][y]==0){
                        cnt++;
                    }
                    b[x-1][y]=1;
                    x--;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,cnt=1;
        char a[1005][1005];
        bool b[1005][1005];
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=true;
            }
        }
        while(k--){
            if(d==0){
                if(a[x][y+1]=='.'&&y<m){
                    y++;
                    if(b[x][y]){
                        cnt++;
                        b[x][y]=false;
                    }
                }
                else d=(d+1)%4;
            }else if(d==1){
                if(a[x+1][y]=='.'&&x<n){
                    x++;
                    if(b[x][y]){
                        cnt++;
                        b[x][y]=false;
                    }
                }
                else d=(d+1)%4;
            }else if(d==2){
                if(a[x][y-1]=='.'&&y>=2){
                    y--;
                    if(b[x][y]){
                        cnt++;
                        b[x][y]=false;
                    }
                }
                else d=(d+1)%4;
            }else{
                if(a[x-1][y]=='.'&&x>=2){
                    x--;
                    if(b[x][y]){
                        cnt++;
                        b[x][y]=false;
                    }
                }
                else d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
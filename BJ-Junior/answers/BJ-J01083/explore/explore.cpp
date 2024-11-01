#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool flag[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(flag,0,sizeof flag);
        int n,m,k,cnt=1;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        flag[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
        while(k--){
        if(d==0){
            if(a[x][y+1]=='.'&&y+1<=m){
                y++;
                if(!flag[x][y]){
                    cnt++;
                    flag[x][y]=1;
                }
            }else{
                d=(d+1)%4;
                continue;
            }
        }else if(d==1){
            if(a[x+1][y]=='.'&&x+1<=n){
                x++;
                if(!flag[x][y]){
                    cnt++;
                    flag[x][y]=1;
                }
            }else{
                d=(d+1)%4;
                continue;
            }
        }else if(d==2){
            if(a[x][y-1]=='.'&&y-1>=1){
                y--;
                if(!flag[x][y]){
                    cnt++;
                    flag[x][y]=1;
                }
            }else{
                d=(d+1)%4;
                continue;
            }
        }else if(d==3){
            if(a[x-1][y]=='.'&&x-1>=1){
                x--;
                if(!flag[x][y]){
                    cnt++;
                    flag[x][y]=1;
                }
            }else{
                d=(d+1)%4;
                continue;
            }
        }
    }
    cout<<cnt<<endl;
    }
    return 0;
}
#include<iostream>
#include<stdio.h>
using namespace std;
int t;
int m,n,k;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        bool a[1005][1005]={0};
        int x,y,d;
        int cnt=1;
        bool b[1005][1005]={0};
        bool check[4][1001][1001]={0};
        cin>>x>>y>>d;
        x--;
        y--;
        b[x][y]=1;
        for(int j=0;j<n;j++){
            for(int j1=0;j1<m;j1++){
                char c;
                cin>>c;
                if(c=='.')
                    a[j][j1]=0;
                else
                    a[j][j1]=1;
            }
        }

        for(int j=0;j<k;j++){
            if(check[d][x][y])
                break;
            else
                check[d][x][y]=1;
            if(d==0){
                if(y+1>=m||(a[x][y+1])){
                    d=(d+1)%4;
                    continue;
                } else {
                    y++;
                    if(!b[x][y]){
                        cnt++;
                        b[x][y]=1;
                    }
                }
            } else if(d==1){
                if(x+1>=n||(a[x+1][y])){
                    d=(d+1)%4;
                    continue;
                } else {
                    x++;
                    if(!b[x][y]){
                        cnt++;
                        b[x][y]=1;
                    }
                }
            } else if(d==2){
                if(y-1<0||(a[x][y-1])){
                    d=(d+1)%4;
                    continue;
                } else {
                    y--;
                    if(!b[x][y]){
                        cnt++;
                        b[x][y]=1;
                    }
                }
            } else if(d==3){
                if(x-1<0||(a[x-1][y])){
                    d=(d+1)%4;
                    continue;
                } else {
                    x--;
                    if(!b[x][y]){
                        cnt++;
                        b[x][y]=1;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
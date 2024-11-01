#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",strout);
    int t;
    cin>>t;
    for(int numss=0;numss<t;numss++){
        int cnt=1;
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int maxN=1005;
        char g[maxN][maxN];
        bool ifg[maxN][maxN]={false};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        for(int i=0;i<k;){
            if(d==0){
                if((y+1)<=m&&g[x][y+1]=='.'&&ifg[x][y+1]==false){
                    cnt++;
                    ifg[x][y+1]==true;
                    k--;
                    y++;
                }
                else{
                    d=(d+1)%4;
                    k--;
                }
            }
            else if(d==1){
                if((x+1)<=n&&g[x+1][y]=='.'&&ifg[x+1][y]==false){
                    cnt++;
                    ifg[x+1][y]==true;
                    k--;
                    x++;
                }
                else{
                    d=(d+1)%4;
                    k--;
                }
            }
            else if(d==2){
                if((y-1)>=1&&g[x][y-1]=='.'&&ifg[x][y-1]==false){
                    cnt++;
                    ifg[x][y-1]==true;
                    k--;
                    y--;
                }
                else{
                    d=(d+1)%4;
                    k--;

                }
            }
            else if(d==3){
                if((x-1)>=1&&g[x-1][y]=='.'&&ifg[x-1][y]==false){
                    cnt++;
                    ifg[x-1][y]==true;
                    k--;
                    x--;
                }
                else{
                    d=(d+1)%4;
                    k--;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

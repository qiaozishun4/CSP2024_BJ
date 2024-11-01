#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
int a[1005][1005],b[1005][1005];
char s[1005][1005];
int main(){
    int t,n,m,k,x,y,d,ans=0;
    fin>>t;
    for(int h=1;h<=t;h++){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        fin>>n>>m>>k>>x>>y>>d;
        ans=0;
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                fin>>s[i][j];
                if(s[i][j]=='.'){
                    a[i][j]=1;
                }
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                if(a[x][y+1]==1){
                    b[x][y+1]=1;
                    y=y+1;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(a[x+1][y]==1){
                    b[x+1][y]=1;
                    x=x+1;
                }else{
                    d=2;
                }
            }else if(d==2){
                if(a[x][y-1]==1){
                    b[x][y-1]=1;
                    y=y-1;
                }else{
                    d=3;
                }
            }else if(d==3){
                if(a[x-1][y]==1){
                    b[x-1][y]=1;
                    x=x-1;
                }else{
                    d=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1){
                    ans++;
                }
            }
        }
        fout<<ans<<endl;
    }
    return 0;
}

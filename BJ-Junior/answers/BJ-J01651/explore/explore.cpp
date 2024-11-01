#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define For(v,s,e) for(int v=s;v<=e;v++)
using namespace std;
int T,m,n,k;
char a[1038][1038],b[1038][1038];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    For(i,1,T){
        int x,y,d;
        cin>>m>>n>>k>>x>>y>>d;
        For(i,1,m)For(j,1,n){
            cin>>a[i][j];
        }
        memset(b,' ',sizeof(b));
        b[x][y]='L';
        For(i,1,k){
            int dx=x,dy=y;
            if(d==0){
                dy++;
            }else if(d==1){
                dx++;
            }else if(d==2){
                dy--;
            }else if(d==3){
                dx--;
            }if(x>=1&&x<=m&&y>=1&&y<=n&&a[dx][dy]=='.')x=dx,y=dy;
            else d=(d+1)%4;
            b[x][y]='L';
       }
        int c=0;
        For(i,1,m)For(j,1,n){
            if(b[i][j]=='L')c++;
        }
        cout<<c<<endl;
    }
    return 0;
}

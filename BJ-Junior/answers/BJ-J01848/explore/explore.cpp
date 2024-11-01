#include<bits/stdc++.h>
using namespace std;
int n_x,n_y;
char a[105][105];
int num[1005];
int right(int d){
    if(d<=2)d++;
    else d=0;
    return d;
}
int nxt(int &x,int &y,int d){
    if(d==0)y++;
    if(d==1)x++;
    if(d==2)y--;
    if(d==3)x--;
    return 1;
}
bool pd(int x,int y,int d){
    nxt(x,y,d);
    if(x==0||x>n_x)return false;
    if(y==0||y>n_y)return false;
    if(a[x][y]=='x')return false;
    return true;
}
int dogo(int x,int y,int d,int c){
    if(c<=0)return -1;

    if(pd(x,y,d)){
        nxt(x,y,d);
    }
    else{
        d=right(d);
    }
    a[x][y]='o';
    dogo(x,y,d,c-1);
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;cin>>n;
    for(int l=1;l<=n;l++){
        int c,qx,qy,d;
        cin>>n_x>>n_y>>c;
        cin>>qx>>qy>>d;

        for(int i=1;i<=n_x;i++){
            for(int j=1;j<=n_y;j++){
                cin>>a[i][j];
            }
        }a[qx][qy]='o';
        dogo(qx,qy,d,c);
        for(int i=1;i<=n_x;i++){
            for(int j=1;j<=n_y;j++){
                if(a[i][j]=='o')num[l]++;
            }
        }
        for(int i=0;i<=104;i++){
            for(int j=0;j<=104;j++){
                a[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<num[i]<<endl;
    }
}
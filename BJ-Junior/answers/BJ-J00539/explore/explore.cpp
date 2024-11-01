#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
int a[1010][1010];
long long wal(int x,int y,int d,int k){
    if(k==0){
        return 1;
    }
    long long px,py;
    if(d==0){
        px=x;
        py=y+1;
    }else if(d==1){
        px=x+1;
        py=y;
    }else if(d==2){
        px=x;
        py=y-1;
    }else if(d==3){
        px=x-1;
        py=y;
    }
    if(px>=1 && px<=n && py>=1 && py<=m && a[px][py]!=1){
        if(a[px][py]==2){
            return wal(px,py,d,k-1);
        }
        a[px][py]=2;
        return wal(px,py,d,k-1)+1;
    }
    return wal(x,y,(d+1)%4,k-1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int h=1;h<=t;h++){
        int k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=0;
                char c;
                cin>>c;
                if(c=='x'){
                    a[i][j]=1;
                }
            }
        }
        a[x][y]=2;
        cout<<wal(x,y,d,k)<<endl;
    }
    return 0;
}

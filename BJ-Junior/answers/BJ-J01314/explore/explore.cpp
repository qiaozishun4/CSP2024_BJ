#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long const N=2011;
long long turnx[4]={0,1,0,-1},turny[4]={1,0,-1,0},c0,n,m,f0=0,f[2*N][2*N];
char a[2*N][2*N];
void dfs(long long x,long long y,long long chao_xiang,long long sum){
    long long i;
    while(1){
        if(sum>c0){
            return ;
        }
        if(f[x][y]==0){
            f0++;
            f[x][y]=1;
        }
//        cout<<x<<" "<<y<<" "<<sum<<" "<<chao_xiang<<"\n";
        if(a[x+turnx[chao_xiang]][y+turny[chao_xiang]]=='.'&&!(x+turnx[chao_xiang]>n||y+turny[chao_xiang]>m||x+turnx[chao_xiang]<1||y+turny[chao_xiang]<1)){
            x=x+turnx[chao_xiang];
            y=y+turny[chao_xiang];

        }
        else{
            chao_xiang=(chao_xiang+1)%4;
        }
        sum++;
    }


    return ;
}
int main(){
    long long i,j,c1,c2,f1=0,f2=0,T,x,y;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        f0=0;
 //       cout<<"a";
        cin>>n>>m>>c0>>x>>y>>c1;
        memset(f,0,sizeof(f));

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>a[i][j];

            }
            f1++;
 //           cout<<i<<" "<<j<<endl;
        }
 //       cout<<"b"<<endl;
        dfs(x,y,c1,0);
        cout<<f0<<"\n";
    }

    return 0;
}


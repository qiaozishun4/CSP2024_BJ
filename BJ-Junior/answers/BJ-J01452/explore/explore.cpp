#include<bits/stdc++.h>
using namespace std;
int v[5][1010][1010]={};
char a[1010][1010]={};
int ccc[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long cnt=0;
long long n,m,k;
long long x,y,d;
long long t;
bool check(int zzx,int zzy){
    if(zzx<1||zzx>n||zzy<1||zzy>m||a[zzx][zzy]=='x') return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int kkk=0;kkk<t;kkk++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int zn=x,zm=y;
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int zx=x+ccc[d][0];
            int zy=y+ccc[d][1];
            if(check(zx,zy)){
                x=zx;y=zy;
                if(v[kkk][x][y]==0) cnt++;
                v[kkk][x][y]=1;
            }else{
                d++;d%=4;
            }
        }
        if(v[kkk][zn][zm]==0){
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
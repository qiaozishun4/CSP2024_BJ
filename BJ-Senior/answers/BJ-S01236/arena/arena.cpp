#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int aa[100009];
int a[100009];
int c[100009];
int ans[100009];
int x[9];
bool d[200009][23];
int sum[200009][23];
int kn[200009][23];
int hl[200009];
void prt(){
    int an;
    an=0;
    for(int i=1;i<=m;i++){
        an^=(ans[c[i]]*i);
    }
    cout<<an<<endl;
}
void inite(){
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++){
        a[i]=(aa[i]^(x[i%4]));
    }
    for(int i=1;i<=n;i++){
        ans[i]=kn[1][i]=0;
        sum[1][i]=i;
        hl[i]=0;
    }
}
void sc(int x,int y){
    if(x==1){
        kn[x][y]=hl[y];
        return;
    }
    int l,r;
    l=y*2;
    r=y*2+1;
    if(!kn[x-1][l]){
        sum[x][y]=sum[x-1][l]+sum[x-1][r];
    }else if(kn[x-1][l]&&!kn[x-1][r]){
        if(d[x][y]){
            kn[x][y]=kn[x-1][l];
            sum[x][y]=sum[x-1][l]+sum[x-1][r];
        }else{
            if(kn[x-1][l]<x){
                kn[x][y]=0;
                sum[x][y]=sum[x-1][l]+sum[x-1][r]-kn[x-1][l];
            }else{
                kn[x][y]=kn[x-1][l];
                sum[x][y]=sum[x-1][l]+sum[x-1][r];
            }
        }
    }else if(kn[x-1][l]&&kn[x-1][r]){
        if(d[x][y]){
            if(kn[x-1][r]<x){
                kn[x][y]=kn[x-1][l];
                sum[x][y]=sum[x-1][l]+sum[x-1][r]-kn[x-1][r];
            }else{
                kn[x][y]=kn[x-1][r];
                sum[x][y]=sum[x-1][l]+sum[x-1][r];
            }
        }else{
            if(kn[x-1][l]<x){
                kn[x][y]=kn[x-1][r];
                sum[x][y]=sum[x-1][r];
            }else{
                kn[x][y]=kn[x-1][l];
                sum[x][y]=sum[x-1][l];
            }
        }
    }
}
void _main(){
    inite();
    ans[1]=sum[1][0]=1;
    int kk;
    kk=0;
    hl[1]=a[1];
    sc(1,1);
    for(int i=2;i<=n;i++){
        hl[i]=a[i];
        if((1ll<<((int)__lg(i-1)))){
            kk++;
            for(int x=1;x<=kk+1;x++){
                for(int j=(1ll<<(kk-1))+1;j<=(1ll<<kk);j++){
                    sc(x,j);
                }
            }
        }
        int z;
        z=i;
        int pp;
        pp=1;
        while(z){
            sc(pp,z);
            pp++;
            z>>=1;
        }
        sc(pp,z);
        ans[i]=sum[kk][0];
    }
    prt();
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int k;
    k=0;
    while((1ll<<k)<n){
        k++;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<(1ll<<(k-i));j++){
            char s;
            cin>>s;
            s-='0';
            d[j][i]=s;
        }
    }
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}

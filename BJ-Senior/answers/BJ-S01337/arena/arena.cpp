#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a1[100005],a[100005],c[100005],t,x[4];
int f[100005];
bool d[1000][100005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a1[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int K,T;
    for(K=0,T=1;T<n;K++,T*=2);
    for(int i=1;i<=K;i++){
        T/=2;
        for(int j=1;j<=T;j++){
            char c;
            cin>>c;
            d[i][j]=(c=='1')?true:false;
        }
    }
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++) a[i]=a1[i]^x[i%4];
        long long ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=c[i];j++) f[j]=j;
            int k,t;
            for(k=0,t=1;t<c[i];k++,t*=2);
            for(int j=1;j<k;j++){
                t/=2;
                for(int l=1;l<=t;l++){
                    if(!d[i][l]){
                        if(a[f[l*2-1]]>=j) f[l]=f[l*2-1];
                        else f[l]=f[l*2];
                    }else{
                        if(a[f[l*2]]>=j) f[l]=f[l*2];
                        else f[l]=f[l*2-1];
                    }
                }
            }
            ans^=(i*f[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
6.在认证过程中，考点各考场统一提供草稿纸（A4打印纸）。草稿纸不足时，认证者可举手向监考示意并索要。————《考生须知》
草稿纸就那一张，自己规划着用。————BJ某考点老师
*/
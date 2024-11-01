#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t,n,m,kk;
int a[N],c[N];
bool d[30][N];
int pp[30];
int xx[4];
int main(){
        freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    pp[0]=1;
    for(int i=1;i<=30;i++) pp[i]=(pp[i-1]<<1);
    for(kk=1;pp[kk-1]<n;kk++);
    for(int i=1;i<=kk;i++){
        for(int j=1;j<=pp[kk-i];j++){
            char c;
            cin>>c;
            d[i][j]=(c=='1');
        }
    }
    cin>>t;
    while(t--){
        cin>>xx[0]>>xx[1]>>xx[2]>>xx[3];
        for(int i=1;i<=n;i++){
            a[i]=(a[i]^xx[i%4]);
        }
        int ans[N];
        int aans;
        for(int ii=1;ii<=m;ii++){
            for(int i=1;i<=n;i++) ans[i]=a[i];
            for(int i=1;pp[i]<=c[ii];i++){
                for(int j=1,jj=1;j<=c[ii];j+=pp[i],jj++){
                    if(d[i][jj]){
                        if(ans[j+pp[i-1]]>=i){
                            swap(ans[j],ans[j+pp[i-1]]);
                        }
                    }
                    else if(ans[j]<i) swap(ans[j],ans[j+pp[i-1]]);
                }
            }
            aans=(aans^(ans[1]*ii));
        }
        cout<<aans<<endl;
    }
    return 0;
}

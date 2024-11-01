#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,m,k,t,a[maxn],c[maxn],com[17][1<<16],ans[maxn];
void solve(){
    int re;
    int x[4];
    for(int i=0;i<4;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=(a[i]||x[i])%4;
    }
    for(int i=1;i<=m;i++){
        if(c[i]==1) ans[i]=1;
        else{
            int may;
            for(int j=1;j<=k;j++){
                for(int i=1;i<=c[i]/2;i++){
                    if(com[j][i]==0){
                        //a[i]
                        if(a[i]>=j){
                            may=c[i];
                        }
                        else{
                            may=c[i+1];
                        }
                    }
                    else{
                        if(a[i+1]>=j){
                            may=c[i];
                        }
                        else{
                            may=c[i+1];
                        }
                    }
                }
            }
            ans[i]=may;
        }
    }
    re=ans[1];
    for(int i=2;i<=m;i++){
        re=re||(i*ans[i]);
    }
    cout<<re<<endl;
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    if((2<<(n>>2))<n)k=(n>>2)+1;
    else k=(n>>2);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=1<<(k-i);j++){
            cin>>com[i][j];
        }
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}